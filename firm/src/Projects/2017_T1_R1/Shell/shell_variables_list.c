/* -----------------------------------------------------------------------------
 * BlueBoard
 * I-Grebot 2017
 * -----------------------------------------------------------------------------
 * @file       shell_variables_list.c
 * @author     Bebop35 [Paul M]
 * @date       Jan 6, 2017
 * -----------------------------------------------------------------------------
 * @brief
 *   Details the variables that are accessible through the shell
 * -----------------------------------------------------------------------------
 * Versionning informations
 * Repository: https://github.com/I-Grebot/firm_blueboard.git
 * -----------------------------------------------------------------------------
 */

#include "blueboard.h"

/* External variables; for setting and probing */
extern OS_SHL_ConfigTypeDef OS_SHL_Config;
extern RobotTypeDef robot;

/*
 * Variables definition list holder
 * Do not leave "unit" column empty! Leave 'NA' if not applicable
 *
 */

const OS_SHL_VarItemTypeDef OS_SHL_varList[] = {

        // System
         {"sys.shell.echo"              , TYPE_BOOL,  ACC_WR, &OS_SHL_Config.echo,                      "NA"}

         // Physical configuration of the robot
         ,{"robot.cs.pos.phys.track"    , TYPE_DOUBLE,  ACC_WR, &robot.cs.pos.phys.track_mm,                   "mm"}
         ,{"robot.cs.pos.phys.dist"     , TYPE_DOUBLE,  ACC_WR, &robot.cs.pos.phys.distance_imp_per_mm,        "imp/mm"}
         ,{"robot.cs.left_gain"         , TYPE_FLOAT,   ACC_WR, &robot.cs.rs.left_ext_gain,                    "NA"}
         ,{"robot.cs.right_gain"        , TYPE_FLOAT,   ACC_WR, &robot.cs.rs.right_ext_gain,                   "NA"}
#ifdef CONFIG_MODULE_COMPENSATE_CENTRIFUGAL_FORCE
         ,{"robot.cs.centrifugal"       , TYPE_DOUBLE,  ACC_WR, &robot.cs.rs.centrifugal_coef,                 "NA"}
#endif

         // Motion configuration for D filter
         ,{"robot.cs.pid_d.kp"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_d.gain_P,                   "NA"}
         ,{"robot.cs.pid_d.ki"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_d.gain_I,                   "NA"}
         ,{"robot.cs.pid_d.kd"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_d.gain_D,                   "NA"}
         ,{"robot.cs.pid_d.max_in"      , TYPE_INT32,  ACC_WR, &robot.cs.pid_d.max_in,                   "NA"}
         ,{"robot.cs.pid_d.max_i"       , TYPE_INT32,  ACC_WR, &robot.cs.pid_d.max_I,                    "NA"}
         ,{"robot.cs.pid_d.max_out"     , TYPE_INT32,  ACC_WR, &robot.cs.pid_d.max_out,                  "NA"}
         ,{"robot.cs.pid_d.out_shift"   , TYPE_UINT8,  ACC_WR, &robot.cs.pid_d.out_shift,                "NA"}
         ,{"robot.cs.pid_d.drv_filter"  , TYPE_UINT8,  ACC_WR, &robot.cs.pid_d.derivate_nb_samples,      "NA"}
         ,{"robot.cs.qr_d.pos_speed"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_d.var_1st_ord_pos,           "mm/imp"}
         ,{"robot.cs.qr_d.neg_speed"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_d.var_1st_ord_neg,           "mm/imp"}
         ,{"robot.cs.qr_d.pos_accel"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_d.var_2nd_ord_pos,           "mm/imp2"}
         ,{"robot.cs.qr_d.neg_accel"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_d.var_2nd_ord_neg,           "mm/imp2"}

         // Motion configuration for A filter
         ,{"robot.cs.pid_a.kp"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_a.gain_P,                   "NA"}
         ,{"robot.cs.pid_a.ki"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_a.gain_I,                   "NA"}
         ,{"robot.cs.pid_a.kd"          , TYPE_INT16,  ACC_WR, &robot.cs.pid_a.gain_D,                   "NA"}
         ,{"robot.cs.pid_a.max_in"      , TYPE_INT32,  ACC_WR, &robot.cs.pid_a.max_in,                   "NA"}
         ,{"robot.cs.pid_a.max_i"       , TYPE_INT32,  ACC_WR, &robot.cs.pid_a.max_I,                    "NA"}
         ,{"robot.cs.pid_a.max_out"     , TYPE_INT32,  ACC_WR, &robot.cs.pid_a.max_out,                  "NA"}
         ,{"robot.cs.pid_a.out_shift"   , TYPE_UINT8,  ACC_WR, &robot.cs.pid_a.out_shift,                "NA"}
         ,{"robot.cs.pid_a.drv_filter"  , TYPE_UINT8,  ACC_WR, &robot.cs.pid_a.derivate_nb_samples,      "NA"}
         ,{"robot.cs.qr_a.pos_speed"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_a.var_1st_ord_pos,           "deg/imp"}
         ,{"robot.cs.qr_a.neg_speed"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_a.var_1st_ord_neg,           "deg/imp"}
         ,{"robot.cs.qr_a.pos_accel"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_a.var_2nd_ord_pos,           "deg/imp2"}
         ,{"robot.cs.qr_a.neg_accel"    , TYPE_UINT32, ACC_WR, &robot.cs.qr_a.var_2nd_ord_neg,           "deg/imp2"}

         // Motion feedbacks
         ,{"robot.cs.pos.x"           , TYPE_INT16, ACC_RD, &robot.cs.pos.pos_s16.x,          "mm"}
         ,{"robot.cs.pos.y"           , TYPE_INT16, ACC_RD, &robot.cs.pos.pos_s16.y,          "mm"}
         ,{"robot.cs.pos.a"           , TYPE_INT16, ACC_RD, &robot.cs.pos.pos_s16.a,          "deg"}
         ,{"robot.cs.speed.d"         , TYPE_INT16, ACC_RD, &robot.cs.speed_d,                "mm/imp"}
         ,{"robot.cs.speed.a"         , TYPE_INT16, ACC_RD, &robot.cs.speed_a,                "deg/imp"}
         ,{"robot.cs.accel.d"         , TYPE_INT16, ACC_RD, &robot.cs.acceleration_d,         "deg/imp2"}
         ,{"robot.cs.accel.a"         , TYPE_INT16, ACC_RD, &robot.cs.acceleration_a,         "mm/imp2"}
         ,{"robot.cs.cs_d.consign"    , TYPE_INT32, ACC_RD, &robot.cs.cs_d.consign_value,     "mm"}
         ,{"robot.cs.cs_d.output"     , TYPE_INT32, ACC_RD, &robot.cs.cs_d.out_value,         "mm"}
         ,{"robot.cs.cs_d.error"      , TYPE_INT32, ACC_RD, &robot.cs.cs_d.error_value,       "mm"}
         ,{"robot.cs.cs_a.consign"    , TYPE_INT32, ACC_RD, &robot.cs.cs_a.consign_value,     "deg"}
         ,{"robot.cs.cs_a.output"     , TYPE_INT32, ACC_RD, &robot.cs.cs_a.out_value,         "deg"}
         ,{"robot.cs.cs_a.error"      , TYPE_INT32, ACC_RD, &robot.cs.cs_a.error_value,       "deg"}
};
const size_t OS_SHL_varListLength = sizeof(OS_SHL_varList) / sizeof(OS_SHL_VarItemTypeDef);
