/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * About Marlin
 *
 * This firmware is a mashup between Sprinter and grbl.
 *  - https://github.com/kliment/Sprinter
 *  - https://github.com/grbl/grbl
 */

#include "MarlinCore.h"

#include "core/utility.h"
// #include "lcd/ultralcd.h"
#include "module/motion.h"
#include "module/planner.h"
#include "module/stepper.h"
#include "module/endstops.h"
#include "module/probe.h"
#include "module/temperature.h"
#include "sd/cardreader.h"
#include "module/configuration_store.h"
#include "module/printcounter.h" // PrintCounter or Stopwatch
// #include "feature/closedloop.h"

#include "HAL/shared/Delay.h"

#include "module/stepper/indirection.h"

#ifdef ARDUINO
#include <pins_arduino.h>
#endif
#include <math.h>
#include "libs/nozzle.h"

#include "gcode/gcode.h"
#include "gcode/parser.h"
#include "gcode/queue.h"

// perron add include
#ifdef POWER_SAVE
#include "wtlib/WTCounter.h"
#endif
#include "wtlib/WTCMD.h"
#include "wtlib/WTHardware.h"
#include "wtlib/WTPacket.h"

#ifdef DGUS_LCD
#include "wtdgus/WTDGUSManager.h"
#endif

// perron add var
uint8_t wtvar_showWelcome = 0;
uint8_t wtvar_gohome = 0;
uint8_t wtvar_goDebugMenu = 0;
uint8_t wtvar_enablefilamentruncout = 0;
uint8_t wtvar_language = 0;
uint8_t wtvar_enablepoweroff = 0;
uint8_t wtvar_enableselftest = 0;
uint8_t wtvar_counter = 0;
uint8_t wtvar_skipTest = 0;
uint8_t wtvar_tune_x1 = 3;
uint8_t wtvar_tune_x2 = 5;
uint8_t wtvar_tune_y = 5;
uint8_t wtvar_runout = 0;
uint32_t nowtime;
bool readykill = false;
int progressvalue;
const char* killmsg = NULL;
InPacket inp3;
OutPacket outp3;

extern char ipAddress[16];
extern char esp32_name[12];
extern char esp32_hardware[8];
extern char esp32_version[8];
extern char esp32_serial[16];
extern char tb_state[20];
extern char esp32_ap[32];

#if ENABLED(TOUCH_BUTTONS)
#include "feature/touch/xpt2046.h"
#endif

#if ENABLED(HOST_ACTION_COMMANDS)
#include "feature/host_actions.h"
#endif

#if USE_BEEPER
#include "libs/buzzer.h"
#endif

#if ENABLED(DIGIPOT_I2C)
#include "feature/digipot/digipot.h"
#endif

#if ENABLED(MIXING_EXTRUDER)
#include "feature/mixing.h"
#endif

#if ENABLED(MAX7219_DEBUG)
#include "feature/max7219.h"
#endif

#if HAS_COLOR_LEDS
#include "feature/leds/leds.h"
#endif

#if ENABLED(BLTOUCH)
#include "feature/bltouch.h"
#endif

#if ENABLED(POLL_JOG)
#include "feature/joystick.h"
#endif

#if HAS_SERVOS
#include "module/servo.h"
#endif

#if ENABLED(DAC_STEPPER_CURRENT)
#include "feature/dac/stepper_dac.h"
#endif

#if ENABLED(EXPERIMENTAL_I2CBUS)
#include "feature/twibus.h"
TWIBus i2c;
#endif

#if ENABLED(I2C_POSITION_ENCODERS)
#include "feature/encoder_i2c.h"
#endif

#if HAS_TRINAMIC_CONFIG && DISABLED(PSU_DEFAULT_OFF)
#include "feature/tmc_util.h"
#endif

#if HAS_CUTTER
#include "feature/spindle_laser.h"
#endif

#if ENABLED(SDSUPPORT)
CardReader card;
#endif

#if ENABLED(G38_PROBE_TARGET)
uint8_t G38_move;     // = 0
bool G38_did_trigger; // = false
#endif

#if ENABLED(DELTA)
#include "module/delta.h"
#elif IS_SCARA
#include "module/scara.h"
#endif

#if HAS_LEVELING
#include "feature/bedlevel/bedlevel.h"
#endif

#if BOTH(ADVANCED_PAUSE_FEATURE, PAUSE_PARK_NO_STEPPER_TIMEOUT)
#include "feature/pause.h"
#endif

#if ENABLED(POWER_LOSS_RECOVERY)
#include "feature/powerloss.h"
#endif

#if ENABLED(CANCEL_OBJECTS)
#include "feature/cancel_object.h"
#endif

#if HAS_FILAMENT_SENSOR
#include "feature/runout.h"
#endif

#if ENABLED(TEMP_STAT_LEDS)
#include "feature/leds/tempstat.h"
#endif

#if HAS_CASE_LIGHT
#include "feature/caselight.h"
#endif

#if HAS_FANMUX
#include "feature/fanmux.h"
#endif

#if DO_SWITCH_EXTRUDER || ANY(SWITCHING_NOZZLE, PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER, ELECTROMAGNETIC_SWITCHING_TOOLHEAD, SWITCHING_TOOLHEAD)
#include "module/tool_change.h"
#endif

#if ENABLED(USE_CONTROLLER_FAN)
#include "feature/controllerfan.h"
#endif

#if ENABLED(PRUSA_MMU2)
#include "feature/mmu2/mmu2.h"
#endif

#if HAS_L64XX
#include "libs/L64XX/L64XX_Marlin.h"
#endif

const char NUL_STR[] PROGMEM = "",
                     M112_KILL_STR[] PROGMEM = "M112 Shutdown",
                     G28_STR[] PROGMEM = "G28",
                     M21_STR[] PROGMEM = "M21",
                     M23_STR[] PROGMEM = "M23 %s",
                     M24_STR[] PROGMEM = "M24",
                     SP_P_STR[] PROGMEM = " P",
                     SP_T_STR[] PROGMEM = " T",
                     SP_X_STR[] PROGMEM = " X",
                     SP_Y_STR[] PROGMEM = " Y",
                     SP_Z_STR[] PROGMEM = " Z",
                     SP_E_STR[] PROGMEM = " E",
                     X_LBL[] PROGMEM = "X:",
                     Y_LBL[] PROGMEM = "Y:",
                     Z_LBL[] PROGMEM = "Z:",
                     E_LBL[] PROGMEM = "E:",
                     SP_X_LBL[] PROGMEM = " X:",
                     SP_Y_LBL[] PROGMEM = " Y:",
                     SP_Z_LBL[] PROGMEM = " Z:",
                     SP_E_LBL[] PROGMEM = " E:";

MarlinState marlin_state = MF_INITIALIZING;

// For M109 and M190, this flag may be cleared (by M108) to exit the wait loop
bool wait_for_heatup = true;

// For M0/M1, this flag may be cleared (by M108) to exit the wait-for-user loop
#if HAS_RESUME_CONTINUE
bool wait_for_user; // = false;
#endif

// Inactivity shutdown
millis_t max_inactive_time, // = 0
    stepper_inactive_time = (DEFAULT_STEPPER_DEACTIVE_TIME)*1000UL;

#if PIN_EXISTS(CHDK)
extern millis_t chdk_timeout;
#endif

#if ENABLED(I2C_POSITION_ENCODERS)
I2CPositionEncodersMgr I2CPEM;
#endif

/**
 * ***************************************************************************
 * ******************************** FUNCTIONS ********************************
 * ***************************************************************************
 */

void setup_killpin()
{
#if HAS_KILL
    SET_INPUT_PULLUP(KILL_PIN);
#endif
}

void setup_powerhold()
{
#if HAS_SUICIDE
    OUT_WRITE(SUICIDE_PIN, !SUICIDE_PIN_INVERTING);
#endif
#if ENABLED(PSU_CONTROL)
    powersupply_on = ENABLED(PSU_DEFAULT_OFF);
    if (ENABLED(PSU_DEFAULT_OFF))
        PSU_OFF();
    else
        PSU_ON();
#endif
}

/**
 * Stepper Reset (RigidBoard, et.al.)
 */
#if HAS_STEPPER_RESET
void disableStepperDrivers()
{
    OUT_WRITE(STEPPER_RESET_PIN, LOW);
} // Drive down to keep motor driver chips in reset
void enableStepperDrivers() { SET_INPUT(STEPPER_RESET_PIN); } // Set to input, allowing pullups to pull the pin high
#endif

#if ENABLED(EXPERIMENTAL_I2CBUS) && I2C_SLAVE_ADDRESS > 0

void i2c_on_receive(int bytes)
{ // just echo all bytes received to serial
    i2c.receive(bytes);
}

void i2c_on_request()
{ // just send dummy data for now
    i2c.reply("Hello World!\n");
}

#endif

/**
 * Sensitive pin test for M42, M226
 */

#include "pins/sensitive_pins.h"

bool pin_is_protected(const pin_t pin)
{
    static const pin_t sensitive_pins[] PROGMEM = SENSITIVE_PINS;
    LOOP_L_N(i, COUNT(sensitive_pins))
    {
        pin_t sensitive_pin;
        memcpy_P(&sensitive_pin, &sensitive_pins[i], sizeof(pin_t));
        if (pin == sensitive_pin)
            return true;
    }
    return false;
}

void protected_pin_err()
{
    SERIAL_ERROR_MSG(STR_ERR_PROTECTED_PIN);
}

void quickstop_stepper()
{
    planner.quick_stop();
    planner.synchronize();
    set_current_from_steppers_for_axis(ALL_AXES);
    sync_plan_position();
}

void enable_e_steppers()
{
#define _ENA_E(N) ENABLE_AXIS_E##N();
    REPEAT(E_STEPPERS, _ENA_E)
}

void enable_all_steppers()
{
#if ENABLED(AUTO_POWER_CONTROL)
    powerManager.power_on();
#endif
    ENABLE_AXIS_X();
    ENABLE_AXIS_Y();
    ENABLE_AXIS_Z();
    enable_e_steppers();
}

void disable_e_steppers()
{
#define _DIS_E(N) DISABLE_AXIS_E##N();
    REPEAT(E_STEPPERS, _DIS_E)
}

void disable_e_stepper(const uint8_t e)
{
#define _CASE_DIS_E(N)       \
    case N:                  \
        DISABLE_AXIS_E##N(); \
        break;
    switch (e)
    {
        REPEAT(EXTRUDERS, _CASE_DIS_E)
    }
}

void disable_all_steppers()
{
    DISABLE_AXIS_X();
    DISABLE_AXIS_Y();
    DISABLE_AXIS_Z();
    disable_e_steppers();
}

#if ENABLED(G29_RETRY_AND_RECOVER)

void event_probe_failure()
{
#ifdef ACTION_ON_G29_FAILURE
    host_action(PSTR(ACTION_ON_G29_FAILURE));
#endif
#ifdef G29_FAILURE_COMMANDS
    gcode.process_subcommands_now_P(PSTR(G29_FAILURE_COMMANDS));
#endif
#if ENABLED(G29_HALT_ON_FAILURE)
#ifdef ACTION_ON_CANCEL
    host_action_cancel();
#endif
    kill(GET_TEXT(MSG_LCD_PROBING_FAILED));
#endif
}

void event_probe_recover()
{
#if ENABLED(HOST_PROMPT_SUPPORT)
    host_prompt_do(PROMPT_INFO, PSTR("G29 Retrying"), DISMISS_STR);
#endif
#ifdef ACTION_ON_G29_RECOVER
    host_action(PSTR(ACTION_ON_G29_RECOVER));
#endif
#ifdef G29_RECOVER_COMMANDS
    gcode.process_subcommands_now_P(PSTR(G29_RECOVER_COMMANDS));
#endif
}

#endif

#if ENABLED(ADVANCED_PAUSE_FEATURE)
#include "feature/pause.h"
#else
constexpr bool did_pause_print = false;
#endif

/**
 * Printing is active when the print job timer is running
 */
bool printingIsActive()
{
    return !did_pause_print && (print_job_timer.isRunning() || IS_SD_PRINTING());
}

/**
 * Printing is paused according to SD or host indicators
 */
bool printingIsPaused()
{
    return did_pause_print || print_job_timer.isPaused() || IS_SD_PAUSED();
}

void startOrResumeJob()
{
    if (!printingIsPaused())
    {
#if ENABLED(CANCEL_OBJECTS)
        cancelable.reset();
#endif
#if ENABLED(LCD_SHOW_E_TOTAL)
        e_move_accumulator = 0;
#endif
#if BOTH(LCD_SET_PROGRESS_MANUALLY, USE_M73_REMAINING_TIME)
        ui.reset_remaining_time();
#endif
    }
    print_job_timer.start();
}

#if ENABLED(SDSUPPORT)

inline void abortSDPrinting()
{
    card.endFilePrint(
#if SD_RESORT
        true
#endif
    );
    queue.clear();
    quickstop_stepper();
    print_job_timer.stop();
#if DISABLED(SD_ABORT_NO_COOLDOWN)
    thermalManager.disable_all_heaters();
#endif
    thermalManager.zero_fan_speeds();
    wait_for_heatup = false;
#if ENABLED(POWER_LOSS_RECOVERY)
    recovery.purge();
#endif
#ifdef EVENT_GCODE_SD_STOP
    queue.inject_P(PSTR(EVENT_GCODE_SD_STOP));
#endif
}

// perron, loop run the case one by one
inline void finishSDPrinting()
{

    bool did_state = true;
    switch (card.sdprinting_done_state)
    {

    case 1:
        did_state = print_job_timer.duration() < 60 || queue.enqueue_one_P(PSTR("M31"));
        break;

    case 2:
        did_state = queue.enqueue_one_P(PSTR("M77"));
        break;

    case 3:
#if ENABLED(LCD_SET_PROGRESS_MANUALLY)
        // ui.set_progress_done();  // perron
#endif
        break;

      case 4:                                   // Display "Click to Continue..."
        // #if HAS_RESUME_CONTINUE                 // 30 min timeout with LCD, 1 min without
        //   did_state = queue.enqueue_one_P(
        //     print_job_timer.duration() < 60 ? PSTR("M0Q1P1") : PSTR("M0Q1S" TERN(HAS_LCD_MENU, "1800", "60"))
        //   );
        // #endif
        break;

    case 5:
#if ENABLED(POWER_LOSS_RECOVERY)
        recovery.purge();
#endif

#if ENABLED(SD_FINISHED_STEPPERRELEASE) && defined(SD_FINISHED_RELEASECOMMAND)
        planner.finish_and_disable();
#endif

#if ENABLED(SD_REPRINT_LAST_SELECTED_FILE)
        ui.reselect_last_file();
#endif

        SERIAL_ECHOLNPGM(STR_FILE_PRINTED);

    default:
        did_state = false;
        card.sdprinting_done_state = 0;
    }
    if (did_state)
        ++card.sdprinting_done_state;
}

#endif // SDSUPPORT

/**
 * Minimal management of Marlin's core activities:
 *  - Check for Filament Runout
 *  - Keep the command buffer full
 *  - Check for maximum inactive time between commands
 *  - Check for maximum inactive time between stepper commands
 *  - Check if an idle but hot extruder needs filament extruded (EXTRUDER_RUNOUT_PREVENT)
 */

inline void manage_inactivity(const bool ignore_stepper_queue = false)
{

#if HAS_FILAMENT_SENSOR
    runout.run();
#endif

    if (queue.length < BUFSIZE)
        queue.get_available_commands();

    const millis_t ms = millis();

    if (max_inactive_time && ELAPSED(ms, gcode.previous_move_ms + max_inactive_time))
    {
        SERIAL_ERROR_START();
        SERIAL_ECHOLNPAIR(STR_KILL_INACTIVE_TIME, parser.command_ptr);
        kill();
    }

// Prevent steppers timing-out in the middle of M600
#define STAY_TEST (BOTH(ADVANCED_PAUSE_FEATURE, PAUSE_PARK_NO_STEPPER_TIMEOUT) && did_pause_print)

    if (stepper_inactive_time)
    {
        static bool already_shutdown_steppers; // = false
        if (planner.has_blocks_queued())
            gcode.reset_stepper_timeout();
        else if (!STAY_TEST && !ignore_stepper_queue && ELAPSED(ms, gcode.previous_move_ms + stepper_inactive_time))
        {
            if (!already_shutdown_steppers)
            {
                already_shutdown_steppers = true; // L6470 SPI will consume 99% of free time without this
                if (ENABLED(DISABLE_INACTIVE_X))
                    DISABLE_AXIS_X();
                if (ENABLED(DISABLE_INACTIVE_Y))
                    DISABLE_AXIS_Y();
                if (ENABLED(DISABLE_INACTIVE_Z))
                    DISABLE_AXIS_Z();
                if (ENABLED(DISABLE_INACTIVE_E))
                    disable_e_steppers();
            }
        }
        else
            already_shutdown_steppers = false;
    }


#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
    if (thermalManager.degHotend(active_extruder) > EXTRUDER_RUNOUT_MINTEMP && ELAPSED(ms, gcode.previous_move_ms + (EXTRUDER_RUNOUT_SECONDS)*1000UL) && !planner.has_blocks_queued())
    {
#if ENABLED(SWITCHING_EXTRUDER)
        bool oldstatus;
        switch (active_extruder)
        {
        default:
            oldstatus = E0_ENABLE_READ();
            ENABLE_AXIS_E0();
            break;
#if E_STEPPERS > 1
        case 2:
        case 3:
            oldstatus = E1_ENABLE_READ();
            ENABLE_AXIS_E1();
            break;
#if E_STEPPERS > 2
        case 4:
        case 5:
            oldstatus = E2_ENABLE_READ();
            ENABLE_AXIS_E2();
            break;
#if E_STEPPERS > 3
        case 6:
        case 7:
            oldstatus = E3_ENABLE_READ();
            ENABLE_AXIS_E3();
            break;
#endif // E_STEPPERS > 3
#endif // E_STEPPERS > 2
#endif // E_STEPPERS > 1
        }
#else // !SWITCHING_EXTRUDER
        bool oldstatus;
        switch (active_extruder)
        {
        default:
#define _CASE_EN(N)                       \
    case N:                               \
        oldstatus = E##N##_ENABLE_READ(); \
        ENABLE_AXIS_E##N();               \
        break;
            REPEAT(E_STEPPERS, _CASE_EN);
        }
#endif

        const float olde = current_position.e;
        current_position.e += EXTRUDER_RUNOUT_EXTRUDE;
        line_to_current_position(MMM_TO_MMS(EXTRUDER_RUNOUT_SPEED));
        current_position.e = olde;
        planner.set_e_position_mm(olde);
        planner.synchronize();

#if ENABLED(SWITCHING_EXTRUDER)
        switch (active_extruder)
        {
        default:
            oldstatus = E0_ENABLE_WRITE(oldstatus);
            break;
#if E_STEPPERS > 1
        case 2:
        case 3:
            oldstatus = E1_ENABLE_WRITE(oldstatus);
            break;
#if E_STEPPERS > 2
        case 4:
        case 5:
            oldstatus = E2_ENABLE_WRITE(oldstatus);
            break;
#endif // E_STEPPERS > 2
#endif // E_STEPPERS > 1
        }
#else // !SWITCHING_EXTRUDER
        switch (active_extruder)
        {
#define _CASE_RESTORE(N)                \
    case N:                             \
        E##N##_ENABLE_WRITE(oldstatus); \
        break;
            REPEAT(E_STEPPERS, _CASE_RESTORE);
        }
#endif // !SWITCHING_EXTRUDER

        gcode.reset_stepper_timeout();
    }
#endif // EXTRUDER_RUNOUT_PREVENT

#if ENABLED(DUAL_X_CARRIAGE)
    // handle delayed move timeout
    if (delayed_move_time && ELAPSED(ms, delayed_move_time + 1000UL) && IsRunning())
    {
        // travel moves have been received so enact them
        delayed_move_time = 0xFFFFFFFFUL; // force moves to be done
        destination = current_position;
        prepare_line_to_destination();
    }
#endif

    // Limit check_axes_activity frequency to 10Hz
    static millis_t next_check_axes_ms = 0;
    if (ELAPSED(ms, next_check_axes_ms))
    {
        planner.check_axes_activity();
        next_check_axes_ms = ms + 100UL;
    }

}

/**
 * Standard idle routine keeps the machine alive
 */
void idle(
#if ENABLED(ADVANCED_PAUSE_FEATURE)
    bool no_stepper_sleep /*=false*/
#endif
)
{
    if (readykill)
      kill(killmsg, nullptr, true);
#if ENABLED(POWER_LOSS_RECOVERY) && PIN_EXISTS(POWER_LOSS)
    recovery.outage();
#endif

#if ENABLED(SPI_ENDSTOPS)
    if (endstops.tmc_spi_homing.any
#if ENABLED(IMPROVE_HOMING_RELIABILITY)
        && ELAPSED(millis(), sg_guard_period)
#endif
    )
    {
        for (uint8_t i = 4; i--;) // Read SGT 4 times per idle loop
            if (endstops.tmc_spi_homing_check())
                break;
    }
#endif

#if ENABLED(MAX7219_DEBUG)
    max7219.idle_tasks();
#endif

    //   ui.update();

#if ENABLED(HOST_KEEPALIVE_FEATURE)
    gcode.host_keepalive();
#endif

    manage_inactivity(
#if ENABLED(ADVANCED_PAUSE_FEATURE)
        no_stepper_sleep
#endif
    );

    thermalManager.manage_heater();

#if ENABLED(PRINTCOUNTER)
    print_job_timer.tick();
#endif

#if USE_BEEPER
    buzzer.tick();
#endif

#if ENABLED(I2C_POSITION_ENCODERS)
    static millis_t i2cpem_next_update_ms;
    if (planner.has_blocks_queued())
    {
        const millis_t ms = millis();
        if (ELAPSED(ms, i2cpem_next_update_ms))
        {
            I2CPEM.update();
            i2cpem_next_update_ms = ms + I2CPE_MIN_UPD_TIME_MS;
        }
    }
#endif

#ifdef HAL_IDLETASK
    HAL_idletask();
#endif

#if HAS_AUTO_REPORTING
    if (!gcode.autoreport_paused)
    {
#if ENABLED(AUTO_REPORT_TEMPERATURES)
        thermalManager.auto_report_temperatures();
#endif
#if ENABLED(AUTO_REPORT_SD_STATUS)
        card.auto_report_sd_status();
#endif
    }
#endif

#if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    Sd2Card::idle();
#endif

#if ENABLED(PRUSA_MMU2)
    mmu2.mmu_loop();
#endif

#if ENABLED(POLL_JOG)
    joystick.inject_jog_moves();
#endif

#ifdef DGUS_LCD
    dgus.Update();
#endif

#ifdef POWER_SAVE
    wt_timer.tick();
#endif
}

/**
 * Kill all activity and lock the machine.
 * After this the machine will need to be reset.
 */
void kill(PGM_P const lcd_error/*=nullptr*/, PGM_P const lcd_component/*=nullptr*/, const bool steppers_off/*=false*/) {
  thermalManager.disable_all_heaters();

  SERIAL_ERROR_MSG(STR_ERR_KILLED);

  #if HAS_DISPLAY
    ui.kill_screen(lcd_error ?: GET_TEXT(MSG_KILLED), lcd_component ?: NUL_STR);
  #else
    UNUSED(lcd_error);
    UNUSED(lcd_component);
  #endif

  #ifdef DGUS_LCD
  dgus.ShowErrorMessage(lcd_error);
  #endif

#ifdef ACTION_ON_KILL
    host_action_kill();
#endif

    minkill(steppers_off);
}

void minkill(const bool steppers_off/*=false*/) {

  // Wait a short time (allows messages to get out before shutting down.
  for (int i = 1000; i--;) DELAY_US(600);

  cli(); // Stop interrupts

  // Wait to ensure all interrupts stopped
  for (int i = 1000; i--;) DELAY_US(250);

  // Reiterate heaters off
  thermalManager.disable_all_heaters();

  // Power off all steppers (for M112) or just the E steppers
  steppers_off ? disable_all_steppers() : disable_e_steppers();

  #if ENABLED(PSU_CONTROL)
    PSU_OFF();
  #endif

  #if HAS_SUICIDE
    suicide();
  #endif

  #if HAS_KILL

    // Wait for kill to be released
    while (!READ(KILL_PIN)) watchdog_refresh();

    // Wait for kill to be pressed
    while (READ(KILL_PIN)) watchdog_refresh();

    void (*resetFunc)() = 0;  // Declare resetFunc() at address 0
    resetFunc();                  // Jump to address 0

  #else // !HAS_KILL

    for (;;) watchdog_refresh(); // Wait for reset

  #endif // !HAS_KILL
}

void waitkill(const char* msg)
{
  readykill = true;
  killmsg = msg;
}

/**
 * Turn off heaters and stop the print in progress
 * After a stop the machine may be resumed with M999
 */
void stop()
{
    thermalManager.disable_all_heaters(); // 'unpause' taken care of in here
    print_job_timer.stop();

#if ENABLED(PROBING_FANS_OFF)
    if (thermalManager.fans_paused)
        thermalManager.set_fans_paused(false); // put things back the way they were
#endif

    if (IsRunning())
    {
        SERIAL_ERROR_MSG(STR_ERR_STOPPED);
        // LCD_MESSAGEPGM(MSG_STOPPED);
        safe_delay(350); // allow enough time for messages to get out before stopping
        marlin_state = MF_STOPPED;
    }
}

/**
 * Marlin entry-point: Set up before the program loop
 *  - Set up the kill pin, filament runout, power hold
 *  - Start the serial port
 *  - Print startup messages and diagnostics
 *  - Get EEPROM or default settings
 *  - Initialize managers for:
 *    �? temperature
 *    �? planner
 *    �? watchdog
 *    �? stepper
 *    �? photo pin
 *    �? servos
 *    �? LCD controller
 *    �? Digipot I2C
 *    �? Z probe sled
 *    �? status LEDs
 *    �? Max7219
 */
void setup()
{
    HAL_init();

#if ENABLED(SMART_EFFECTOR) && PIN_EXISTS(SMART_EFFECTOR_MOD)
    OUT_WRITE(SMART_EFFECTOR_MOD_PIN, LOW); // Put Smart Effector into NORMAL mode
#endif

#if ENABLED(DISABLE_DEBUG)
// Disable any hardware debug to free up pins for IO
#ifdef JTAGSWD_DISABLE
    JTAGSWD_DISABLE();
#elif defined(JTAG_DISABLE)
    JTAG_DISABLE();
#else
#error "DISABLE_DEBUG is not supported for the selected MCU/Board"
#endif
#elif ENABLED(DISABLE_JTAG)
// Disable JTAG to free up pins for IO
#ifdef JTAG_DISABLE
    JTAG_DISABLE();
#else
#error "DISABLE_JTAG is not supported for the selected MCU/Board"
#endif
#endif
    JTAG_DISABLE();

#if HAS_FILAMENT_SENSOR
    runout.setup();
#endif

#if ENABLED(POWER_LOSS_RECOVERY)
    recovery.setup();
#endif

    setup_killpin();

    setup_powerhold();

#if HAS_STEPPER_RESET
    disableStepperDrivers();
#endif

// perron, set uart dma mode
#ifdef DMA_RX_SUPPORT
    SerialInit();
#else
#if NUM_SERIAL > 0
    MYSERIAL0.begin(HOST_BAUDRATE);
    uint32_t serial_connect_timeout = millis() + 1000UL;
    while (!MYSERIAL0 && PENDING(millis(), serial_connect_timeout))
    { /*nada*/
    }
#if NUM_SERIAL > 1
    MYSERIAL1.begin(WIFI_BAUDRATE);
    serial_connect_timeout = millis() + 1000UL;
    while (!MYSERIAL1 && PENDING(millis(), serial_connect_timeout))
    { /*nada*/
    }
#endif
#endif
#endif

    // restart wificam
    // WT_ESP32_Restart();
    // safe_delay(500);

    SERIAL_ECHOLNPGM("start");
    PORT_REDIRECT(1);
    SERIAL_ECHOLNPGM("WTSTART");
    PORT_RESTORE();
    SERIAL_ECHO_START();

#if HAS_TMC_SPI
#if DISABLED(TMC_USE_SW_SPI)
    SPI.begin();
#endif
    tmc_init_cs_pins();
#endif

#ifdef BOARD_INIT
    BOARD_INIT();
#endif

    // Check startup - does nothing if bootloader sets MCUSR to 0
    byte mcu = HAL_get_reset_source();
    if (mcu & 1)
        SERIAL_ECHOLNPGM(STR_POWERUP);
    if (mcu & 2)
        SERIAL_ECHOLNPGM(STR_EXTERNAL_RESET);
    if (mcu & 4)
        SERIAL_ECHOLNPGM(STR_BROWNOUT_RESET);
    if (mcu & 8)
        SERIAL_ECHOLNPGM(STR_WATCHDOG_RESET);
    if (mcu & 32)
        SERIAL_ECHOLNPGM(STR_SOFTWARE_RESET);
    HAL_clear_reset_source();

    serialprintPGM(GET_TEXT(MSG_MARLIN));
    SERIAL_CHAR(' ');
    SERIAL_ECHOLNPGM(SHORT_BUILD_VERSION);
    SERIAL_EOL();

#if defined(STRING_DISTRIBUTION_DATE) && defined(STRING_CONFIG_H_AUTHOR)
    SERIAL_ECHO_MSG(
        STR_CONFIGURATION_VER
            STRING_DISTRIBUTION_DATE
                STR_AUTHOR STRING_CONFIG_H_AUTHOR);
    SERIAL_ECHO_MSG("Compiled: " __DATE__);
#endif

    SERIAL_ECHO_START();
    SERIAL_ECHOLNPAIR(STR_FREE_MEMORY, freeMemory(), STR_PLANNER_BUFFER_BYTES, (int)sizeof(block_t) * (BLOCK_BUFFER_SIZE));

    // UI must be initialized before EEPROM
    // (because EEPROM code calls the UI).

#if ENABLED(MARLIN_DEV_MODE)
    auto log_current_ms = [&](PGM_P const msg) {
        SERIAL_ECHO_START();
        SERIAL_CHAR('[');
        SERIAL_ECHO(millis());
        SERIAL_ECHO("] ");
        serialprintPGM(msg);
        SERIAL_EOL();
    };
#define SETUP_LOG(M) log_current_ms(PSTR(M))
#else
#define SETUP_LOG(...) NOOP
#endif
#define SETUP_RUN(C)             \
    do                           \
    {                            \
        SETUP_LOG(STRINGIFY(C)); \
        C;                       \
    } while (0)

// Set up LEDs early
#if HAS_COLOR_LEDS
    SETUP_RUN(leds.setup());
#endif

    //   SETUP_RUN(ui.init());
    //   SETUP_RUN(ui.reset_status());       // Load welcome message early. (Retained if no errors exist.)

#if HAS_SPI_LCD && ENABLED(SHOW_BOOTSCREEN)
    SETUP_RUN(ui.show_bootscreen());
#endif

#if ENABLED(SDSUPPORT) && defined(SDCARD_CONNECTION) && !SD_CONNECTION_IS(LCD)
    SETUP_RUN(card.mount()); // Mount onboard / custom SD card before settings.first_load
#endif

    SETUP_RUN(settings.first_load()); // Load data from EEPROM if available (or use defaults)
                                      // This also updates variables in the planner, elsewhere
#if HAS_SERVICE_INTERVALS
    SETUP_RUN(ui.reset_status(true)); // Show service messages or keep current status
#endif

#if ENABLED(TOUCH_BUTTONS)
    SETUP_RUN(touch.init());
#endif

#if HAS_M206_COMMAND
    current_position += home_offset; // Init current position based on home_offset
#endif

    sync_plan_position(); // Vital to init stepper/planner equivalent for current_position

    SETUP_RUN(thermalManager.init()); // Initialize temperature loop

    SETUP_RUN(print_job_timer.init()); // Initial setup of print job timer

    SETUP_RUN(endstops.init()); // Init endstops and pullups

    SETUP_RUN(stepper.init()); // Init stepper. This enables interrupts!

#if HAS_SERVOS
    SETUP_RUN(servo_init());
#endif

#if HAS_Z_SERVO_PROBE
    SETUP_RUN(probe.servo_probe_init());
#endif

#if HAS_PHOTOGRAPH
    OUT_WRITE(PHOTOGRAPH_PIN, LOW);
#endif

#if HAS_CUTTER
    SETUP_RUN(cutter.init());
#endif

#if ENABLED(COOLANT_MIST)
    OUT_WRITE(COOLANT_MIST_PIN, COOLANT_MIST_INVERT); // Init Mist Coolant OFF
#endif
#if ENABLED(COOLANT_FLOOD)
    OUT_WRITE(COOLANT_FLOOD_PIN, COOLANT_FLOOD_INVERT); // Init Flood Coolant OFF
#endif

#if HAS_BED_PROBE
    SETUP_RUN(endstops.enable_z_probe(false));
#endif

#if ENABLED(USE_CONTROLLER_FAN)
    SET_OUTPUT(CONTROLLER_FAN_PIN);
#endif

#if HAS_STEPPER_RESET
    SETUP_RUN(enableStepperDrivers());
#endif

#if ENABLED(DIGIPOT_I2C)
    SETUP_RUN(digipot_i2c_init());
#endif

#if ENABLED(DAC_STEPPER_CURRENT)
    SETUP_RUN(dac_init());
#endif

#if EITHER(Z_PROBE_SLED, SOLENOID_PROBE) && HAS_SOLENOID_1
    OUT_WRITE(SOL1_PIN, LOW); // OFF
#endif

#if HAS_HOME
    SET_INPUT_PULLUP(HOME_PIN);
#endif

#if ENABLED(MIXING_EXTRUDER)
    SETUP_RUN(mixer.init());
#endif

#if ENABLED(BLTOUCH)
    SETUP_RUN(bltouch.init(/*set_voltage=*/true));
#endif

#if ENABLED(I2C_POSITION_ENCODERS)
    SETUP_RUN(I2CPEM.init());
#endif

#if ENABLED(EXPERIMENTAL_I2CBUS) && I2C_SLAVE_ADDRESS > 0
    SETUP_LOG("i2c...");
    i2c.onReceive(i2c_on_receive);
    i2c.onRequest(i2c_on_request);
#endif

#if DO_SWITCH_EXTRUDER
    SETUP_RUN(move_extruder_servo(0)); // Initialize extruder servo
#endif

#if ENABLED(SWITCHING_NOZZLE)
    SETUP_LOG("SWITCHING_NOZZLE");
// Initialize nozzle servo(s)
#if SWITCHING_NOZZLE_TWO_SERVOS
    lower_nozzle(0);
    raise_nozzle(1);
#else
    move_nozzle_servo(0);
#endif
#endif

#if ENABLED(MAGNETIC_PARKING_EXTRUDER)
    SETUP_RUN(mpe_settings_init());
#endif

#if ENABLED(PARKING_EXTRUDER)
    SETUP_RUN(pe_solenoid_init());
#endif

#if ENABLED(SWITCHING_TOOLHEAD)
    swt_init();
#endif

#if ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    SETUP_RUN(est_init());
#endif

#if ENABLED(USE_WATCHDOG)
    SETUP_RUN(watchdog_init()); // Reinit watchdog after HAL_get_reset_source call
#endif

#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
    SETUP_RUN(init_closedloop());
#endif

#ifdef STARTUP_COMMANDS
    SETUP_LOG("STARTUP_COMMANDS");
    queue.inject_P(PSTR(STARTUP_COMMANDS));
#endif

#if ENABLED(INIT_SDCARD_ON_BOOT) && !HAS_SPI_LCD
    SETUP_RUN(card.beginautostart());
#endif

#if ENABLED(HOST_PROMPT_SUPPORT)
    SETUP_RUN(host_action_prompt_end());
#endif

    marlin_state = MF_RUNNING;

    SETUP_LOG("setup() completed.");

    // perron
    strcpy_P(ipAddress, MSG_WIFINOTCONNECTED); // perron reset the ip address
    strcpy_P(esp32_name, MSG_UNKNOWN);
    strcpy_P(esp32_serial, MSG_UNKNOWN);
    strcpy_P(esp32_version, MSG_UNKNOWN);
    strcpy_P(esp32_hardware, MSG_UNKNOWN);
    strcpy_P(tb_state, MSG_UNKNOWN);
    strcpy_P(esp32_ap, MSG_UNKNOWN);

#ifdef POWER_SAVE
    pinMode(POWEROFF_PIN, OUTPUT);
#endif

    // case fan init
    pinMode(CASE_FAN_PIN, OUTPUT);
    digitalWrite(CASE_FAN_PIN, HIGH);

    if (wtvar_enablefilamentruncout == 0)
        runout.enabled = false;
    else
        runout.enabled = true;

    wtvar_skipTest = 0;
    if (wtvar_gohome == 1)
    {
        queue.enqueue_one_now("G28 X Y F3000");
        queue.enqueue_one_now("G1 Y270");
        queue.enqueue_one_now("M18");
#if ENABLED(POWER_LOSS_RECOVERY)
        card.removeJobRecoveryFile();
#endif
    }

	inp3.SetOutPacket(&outp3);
	inp3.port = 1;
    outp3.port = 1;
	inp3.Reset();
    outp3.Reset();

#ifdef DGUS_LCD
    
    if (wtvar_gohome == 1)
    {
        dgus.Init(DGUS_BAUDRATE, false);
        safe_delay(200); 
    }
    else
    {
        dgus.Init(DGUS_BAUDRATE, true);
        safe_delay(200);
        dgus.Update();
        safe_delay(200);
    }
    nowtime = millis();
    dgus.GotoBootMenu();
    safe_delay(200);
#endif

#ifdef POWER_SAVE
    wt_timer.init();
    wt_timer.SetInterval(wtvar_counter);
#endif

    thermalManager.auto_report_temp_interval = 10;
}

/**
 * The main Marlin program loop
 *
 *  - Call idle() to handle all tasks between G-code commands
 *      Note that no G-codes from the queue can be executed during idle()
 *      but many G-codes can be called directly anytime like macros.
 *  - Check whether SD card auto-start is needed now.
 *  - Check whether SD print finishing is needed now.
 *  - Run one G-code command from the immediate or main command queue
 *    and open up one space. Commands in the main queue may come from sd
 *    card, host, or by direct injection. The queue will continue to fill
 *    as long as idle() or manage_inactivity() are being called.
 */
void loop() {

    if (readykill)
      kill(killmsg, nullptr, true);

    idle();

#if ENABLED(SDSUPPORT)
        //card.checkautostart();    // perron, dgus check the sdcard status
        if (card.flag.abort_sd_printing)
            abortSDPrinting();
        if (card.sdprinting_done_state)
            finishSDPrinting();
#endif

    queue.advance();

    wt_loopaction();

    endstops.event_handler();
}

uint32_t getcurrenttime()
{
    uint32_t timetmp = millis();
    return timetmp;
}
