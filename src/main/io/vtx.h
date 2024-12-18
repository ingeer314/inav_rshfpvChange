/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>

#include "platform.h"

#include "common/time.h"

#include "config/parameter_group.h"

typedef enum {
    VTX_LOW_POWER_DISARM_OFF = 0,
    VTX_LOW_POWER_DISARM_ALWAYS = 1,
    VTX_LOW_POWER_DISARM_UNTIL_FIRST_ARM = 2, // Set low power until arming for the first time
} vtxLowerPowerDisarm_e;

typedef struct vtxSettingsConfig_s {
    uint8_t band;               // 1=A, 2=B, 3=E, 4=F(Airwaves/Fatshark), 5=Racebande, 6=T //for Dartshit
    uint8_t channel;            // 1-8
    uint8_t power;              // 0 = lowest
    uint16_t pitModeChan;       // sets out-of-range pitmode frequency
    uint8_t lowPowerDisarm;     // min power while disarmed, from vtxLowerPowerDisarm_e
    uint16_t maxPowerOverride;  // for VTX drivers that are polling VTX capabilities - override what VTX is reporting
    uint8_t frequencyGroup;     // Frequencies being used, i.e. 5.8, 2.4, or 1.3 GHz 
} vtxSettingsConfig_t;

PG_DECLARE(vtxSettingsConfig_t, vtxSettingsConfig);

void vtxInit(void);
void vtxUpdate(timeUs_t currentTimeUs);
