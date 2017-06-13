/**
 * \file TSL_driver.h
 * \version 1.00
 * \brief this file contains sensor TSL2561's implemented functionality
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * Neither the name of NXP, nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * visit: http://www.mikroe.com and http://www.nxp.com
 *
 * get support at: http://www.mikroe.com/forum and https://community.nxp.com
 *
 * Project HEXIWEAR, 2015
 */

#pragma once

#include "TSL_types.h"

/**
 * initialize the sensor
 * @param  tslHandle    handle to be populated with sensor info
 * @param  tslSettings  user settings
 * @return  status flag
 */
tsl_status_t TSL_Init(
                              handleTSL_t* self,
                      const settingsTSL_t* settings
                    );

/**
 * shut down the sensor
 */
tsl_status_t TSL_Deinit();

/**
 * enable the sensor
 */
void TSL_Enable ();

/**
 * disable the sensor
 */
void TSL_Disable();

/**
 * set sensor gain
 * @param  gain [description]
 * @return      status flag
 */
tsl_status_t TSL_SetGain (
                           gainTSL_t gain
                        );

/**
 * set sensor integration time
 * @param  integration integration time
 * @return             status flag
 */
tsl_status_t TSL_SetTiming (
                            integrationTSL_t integration
                          );

/**
 * read raw sensor data
 * @param  channel    TSL channel (red or infrared)
 * @param  sensorData sensor data to be filled
 * @return            status flag
 */
tsl_status_t TSL_ReadRawData (
                              channelTSL_t channel,
                                 uint16_t* sensorData
                            );

/**
 * calculate luminance
 */
tsl_status_t TSL_CalculateLux(
                              uint16_t* channelValues,
                              uint32_t* luxVal
                            );

/**
 * formatting functions
 */

/**
 * format raw to float
 * @param src original data array
 * @param dst new format data array
 * @param idx index of the sample to be formatted
 */
void ambi_fmtDef2Float(
                        const void* src,
                              void* dst,
                           uint32_t idx
                      );

/**
 * format raw to mE format - currently unimplemented
 */
void ambi_fmtDef2Me(
						const void* src,
							  void* dst,
						   uint32_t idx
					);

/**
 * format raw to byte format
 * @param src original data array
 * @param dst new format data array
 * @param idx index of the sample to be formatted
 */
void ambi_fmtDef2Byte	(
                     		const void* src,
                                  void* dst,
							   uint32_t idx
						);

/**
 * [TSL_FormatLux description]
 * @param luxVal   [description]
 * @param ambLight [description]
 */
void TSL_FormatLux( uint32_t luxVal, uint8_t* ambLight );