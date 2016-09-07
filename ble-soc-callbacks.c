/***********************************************************************************************//**
 * \file   common-soc/ble-soc-callbacks.c
 * \brief  EFR32 application
 ***************************************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

#include "boards.h"

#include CONFIGURATION_HEADER
#include CALLBACKS_HEADER

/* standard library headers */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


/* BG stack headers */
#include "bg_types.h"
#include "native_gecko.h"

/* application specific files */
#include "app.h"
#include "app_ui.h"
#include "platform_hw-callback.h"
#include "app-callback.h"

#ifdef SILABS_AF_PLUGIN_ADVERTISEMENT
#include "advertisement-callback.h"
#endif
#ifdef SILABS_AF_PLUGIN_HTM
#include "htm-callback.h"
#endif
#ifdef SILABS_AF_PLUGIN_IA
#include "ia-callback.h"
#endif
#ifdef SILABS_AF_PLUGIN_BEACON
#include "beacon-callback.h"
#endif
#ifdef SILABS_AF_PLUGIN_CONNECTION
#include "connection-callback.h"
#endif
#ifdef SILABS_AF_PLUGIN_ANC
#include "anc-callback.h"
#endif/* #ifdef SILABS_AF_PLUGIN_ANC */
#ifdef SILABS_AF_PLUGIN_LL
#include "ll-callback.h"
#endif /* SILABS_AF_PLUGIN_LL */
#ifdef SILABS_AF_PLUGIN_CABLE_SERVER
#include "cable_server-callback.h"
#endif /* SILABS_AF_PLUGIN_CABLE_SERVER */
#ifdef SILABS_AF_PLUGIN_CABLE_CLIENT
#include "cable_client-callback.h"
#endif /* SILABS_AF_PLUGIN_CABLE_CLIENT */


/***********************************************************************************************//**
 *  \brief  Main Stack Init.
 *  \details  This function is called when the stack starts and can be used to perform necessary
 *  initialization required at system startup.
 **************************************************************************************************/
void emberAfMainEfr32StackInitCallback(void)
{
  mainEfr32StackInitCallback();
}

/***********************************************************************************************//**
 *  \brief  Main Application Tick.
 *  \details  This function is called in each iteration of the main application loop and can be used
 *  to perform periodic functions. The frequency with which this function is called depends on how
 *  quickly the main loop runs. If the application blocks at any time during the main loop, this
 *  function will not be called until execution resumes.  On SoC platforms, sleeping and idling will
 *  block. On Unix hosts, process yielding (e.g., via select) will block.
 **************************************************************************************************/
void emberAfMainAppTickCallback(void)
{
  mainAppTickCallback();
}

void emberAfPluginResetEventCallback(void)
{
  resetEventCallback();
}

#ifdef SILABS_AF_PLUGIN_HTM
/***********************************************************************************************//**
 *  \brief  A new temperature measurement value is available.
 *  \details  This function is called by the HTM plugin before sending a measurement value.
 *  \param  temperature  Measured Temperature value in Celsius
 **************************************************************************************************/
void emberAfPluginTempMeasAvailableCallback(float temperature)
{
    tempMeasAvailableCallback(temperature);
}
#endif /* SILABS_AF_PLUGIN_HTM */

#ifdef SILABS_AF_PLUGIN_CONNECTION
/***********************************************************************************************//**
 *  \brief  Connection started.
 *  \details  This function is called by the app_cfg plugin after a a connection is made.
 **************************************************************************************************/
void emberAfPluginConnectionOpenedEventCallback(void)
{
  connectionOpenedEventCallback();
}

/***********************************************************************************************//**
 *  \brief  Connection terminated.
 *  \details  This function is called by the app_cfg plugin after a a connection is termninated.
 **************************************************************************************************/
void emberAfPluginConnectionTerminatedEventCallback(void)
{
  connectionTerminatedEventCallback();
}
#endif /* SILABS_AF_PLUGIN_CONNECTION */

#ifdef SILABS_AF_PLUGIN_ADVERTISEMENT
/***********************************************************************************************//**
 *  \brief  Advertising started.
 *  \details  This function is called by the advertising plugin after advertising has been started.
 **************************************************************************************************/
void emberAfPluginAdvertisingStartedCallback(void)
{
  advertisingStartedCallback();
}

/***********************************************************************************************//**
 *  \brief  Advertising stopped.
 *  \details  This function is called by the advertising plugin after advertising has been stopped.
 **************************************************************************************************/
void emberAfPluginAdvertisingStoppedCallback(void)
{
  advertisingStoppedCallback(); 
}
#endif /* SILABS_AF_PLUGIN_ADVERTISEMENT */

#ifdef SILABS_AF_PLUGIN_BEACON
/***********************************************************************************************//**
 *  \brief  Beaconing started.
 *  \details  This function is called by the Beacon plugin after beaconing has been started.
 **************************************************************************************************/
void emberAfPluginBeaconingStartedCallback(void)
{
  beaconingStartedCallback(); 
}
#endif /* SILABS_AF_PLUGIN_BEACON */

#ifdef SILABS_AF_PLUGIN_IA
/***********************************************************************************************//**
 *  \brief  No Alert received.
 *  \details  This function is called by the Immediate Alert plugin after detecting No Alert.
 **************************************************************************************************/
void emberAfPluginIaNoAlertCallback(void)
{
  iaNoAlertCallback();
}

/***********************************************************************************************//**
 *  \brief  Low Alert received.
 *  \details  This function is called by the Immediate Alert plugin after detecting Low Alert.
 **************************************************************************************************/
void emberAfPluginIaLowAlertCallback(void)
{
  iaLowAlertCallback();
}

/***********************************************************************************************//**
 *  \brief  High Alert received.
 *  \details  This function is called by the Immediate Alert plugin after detecting High Alert.
 **************************************************************************************************/
void emberAfPluginIaHighAlertCallback(void)
{
  iaHighAlertCallback();
}
#endif /* SILABS_AF_PLUGIN_IA */

#ifdef SILABS_AF_PLUGIN_ANC
/***********************************************************************************************//**
 *  \brief  Anc Characteristic Value Received.
 *  \details  This function is called by the Apple Notification Service Center, after an ANC
 *  Characteristic Notification was received.
 *  \param  ancCategoryId  ANC Category ID.
 *  \param  ancCategoryCount  The current number of active iOS notifications in the given category. 
 **************************************************************************************************/
void emberAfPluginAncCharValueReceivedCallback(uint8_t ancCategoryId, uint8_t ancCategoryCount)
{ 
  ancCharValueReceivedCallback(ancCategoryId, ancCategoryCount);
}
#endif /* SILABS_AF_PLUGIN_ANC */

#ifdef SILABS_AF_PLUGIN_LL
/***********************************************************************************************//**
 *  \brief  No Alert received.
 *  \details  This function is called by the Link Loss service after detecting Lost link, and No
 *  Alert was set previously as Alert Level.
 **************************************************************************************************/
void emberAfPluginLlNoAlertCallback(void)
{
  llNoAlertCallback();
}

/***********************************************************************************************//**
 *  \brief  Low Alert received.
 *  \details  This function is called by the Link Loss service after detecting Lost link, and Low
 *  Alert was set previously as Alert Level.
 **************************************************************************************************/
void emberAfPluginLlLowAlertCallback(void)
{
  llLowAlertCallback();
}

/***********************************************************************************************//**
 *  \brief  High Alert received.
 *  \details  This function is called by the Link Loss service after detecting Lost link, and High
 *  Alert was set previously as Alert Level.
 **************************************************************************************************/
void emberAfPluginLlHighAlertCallback(void)
{
  llHighAlertCallback();
}
#endif /* SILABS_AF_PLUGIN_LL */

#ifdef SILABS_AF_PLUGIN_CABLE_SERVER
void emberAfPluginCableServerData2ClientCallback(char character)
{
  cableServerData2ClientCallback(character); 
}

void emberAfPluginCableServerCharStatusChangeCallback(uint16_t clientConfig)
{
  cableServerCharStatusChangeCallback(clientConfig);
}
#endif /* SILABS_AF_PLUGIN_CABLE_SERVER */

#ifdef SILABS_AF_PLUGIN_CABLE_CLIENT
void emberAfPluginCableClientData2ServerCallback(char character)
{
  cableClientData2ServerCallback(character);
}

void emberAfPluginCableClientNotificationsEnabledCallback(void)
{
  cableClientNotificationsEnabledCallback();
}
#endif /* SILABS_AF_PLUGIN_CABLE_CLIENT */
