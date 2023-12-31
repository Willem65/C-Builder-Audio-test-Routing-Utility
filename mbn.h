/****************************************************************************
**
** Copyright (C) 2009 D&R Electronica Weesp B.V. All rights reserved.
**
** This file is part of the Axum/MambaNet digital mixing system.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef MBN_H
#define MBN_H

#include <time.h>

/* These two lines should be modified by our Makefile. */
#define MBNP_mingw
#undef MBNP_STATIC

/* check to see if it has indeed been modified */
#ifdef MBNP_PLATFORM
# error MBNP_[platform] not set!
#endif

/* these define which interface modules can be used, for the application */
#define MBN_IF_ETHERNET if_eth_wpcap
#define MBN_IF_TCP if_tcp
#define MBN_IF_UDP if_udp

/* forcing a ManufacturerID? */
/* #undef MBN_MANUFACTURERID */
#define MBN_MANUFACTURERID 1

#ifndef MBN_MANUFACTURERID
  #define MBN_MANUFACTURER_NAME "None" 
#else
  #if MBN_MANUFACTURERID == 1
    #define MBN_MANUFACTURER_NAME "DnR"
  #elif MBN_MANUFACTURERID == 2
    #define MBN_MANUFACTURER_NAME "Broadcast Partners"
  #elif MBN_MANUFACTURERID == 3
    #define MBN_MANUFACTURER_NAME "Prisode"
  #elif MBN_MANUFACTURERID == 4
    #define MBN_MANUFACTURER_NAME "Prosol"
  #elif MBN_MANUFACTURERID == 5
    #define MBN_MANUFACTURER_NAME "Caliope"
  #elif MBN_MANUFACTURERID == 6
    #define MBN_MANUFACTURER_NAME "Radio42"
  #endif
#endif

/* Windows DLLs want flags for exportable functions */
#ifdef MBNP_mingw
# ifndef MBNP_STATIC
#  ifdef MBNP_BUILD
#   define MBN_EXPORT __declspec(dllexport) __stdcall
#  else
#   define MBN_EXPORT __declspec(dllimport) __stdcall
#  endif
# else
#  define MBN_EXPORT
# endif
#else
# define MBN_EXPORT
#endif



/*
 *    G L O B A L   D E F I N E S
 */

/* stack configuration */
#define MBN_ADDR_TIMEOUT    110 /* seconds */
#define MBN_ADDR_MSG_TIMEOUT 30 /* sending address reservation information packets */

#define MBN_ACKNOWLEDGE_RETRIES 15 /* number of times to retry a message requiring an acknowledge */

#define MBN_ERRSIZE 512 /* should be large enough to hold any error message */

/* protocol information */
#define MBN_BROADCAST_ADDRESS 0x10000000

#define MBN_PROTOCOL_VERSION_MAJOR 1
#define MBN_PROTOCOL_VERSION_MINOR 0

#define MBN_MAX_MESSAGE_SIZE 128
#define MBN_MIN_MESSAGE_SIZE 16

/* message types */
#define MBN_MSGTYPE_ADDRESS 0x00
#define MBN_MSGTYPE_OBJECT  0x01

/* address message types */
#define MBN_ADDR_ACTION_INFO     0x00
#define MBN_ADDR_ACTION_PING     0x01
#define MBN_ADDR_ACTION_RESPONSE 0x02

/* flags for node services */
#define MBN_ADDR_SERVICES_SERVER 0x01
#define MBN_ADDR_SERVICES_ENGINE 0x02
#define MBN_ADDR_SERVICES_ERROR  0x40
#define MBN_ADDR_SERVICES_VALID  0x80

/* object action messages */
#define MBN_OBJ_ACTION_GET_INFO           0
#define MBN_OBJ_ACTION_INFO_RESPONSE      1
#define MBN_OBJ_ACTION_GET_ENGINE         2
#define MBN_OBJ_ACTION_ENGINE_RESPONSE    3
#define MBN_OBJ_ACTION_SET_ENGINE         4
#define MBN_OBJ_ACTION_GET_FREQUENCY      5
#define MBN_OBJ_ACTION_FREQUENCY_RESPONSE 6
#define MBN_OBJ_ACTION_SET_FREQUENCY      7
#define MBN_OBJ_ACTION_GET_SENSOR        32
#define MBN_OBJ_ACTION_SENSOR_RESPONSE   33
#define MBN_OBJ_ACTION_SENSOR_CHANGED    34
#define MBN_OBJ_ACTION_GET_ACTUATOR      64
#define MBN_OBJ_ACTION_ACTUATOR_RESPONSE 65
#define MBN_OBJ_ACTION_SET_ACTUATOR      66

/* data types */
#define MBN_DATATYPE_NODATA    0
#define MBN_DATATYPE_UINT      1
#define MBN_DATATYPE_SINT      2
#define MBN_DATATYPE_STATE     3
#define MBN_DATATYPE_OCTETS    4
#define MBN_DATATYPE_FLOAT     5
#define MBN_DATATYPE_BITS      6
#define MBN_DATATYPE_OBJINFO 128
#define MBN_DATATYPE_ERROR   255

/* default node objects */
#define MBN_NODEOBJ_DESCRIPTION      0
#define MBN_NODEOBJ_NAME             1
#define MBN_NODEOBJ_MANUFACTURERID   2
#define MBN_NODEOBJ_PRODUCTID        3
#define MBN_NODEOBJ_UNIQUEID         4
#define MBN_NODEOBJ_HWMAJOR          5
#define MBN_NODEOBJ_HWMINOR          6
#define MBN_NODEOBJ_FWMAJOR          7
#define MBN_NODEOBJ_FWMINOR          8
#define MBN_NODEOBJ_FPGAMAJOR        9
#define MBN_NODEOBJ_FPGAMINOR       10
#define MBN_NODEOBJ_PROTOMAJOR      11
#define MBN_NODEOBJ_PROTOMINOR      12
#define MBN_NODEOBJ_NUMBEROFOBJECTS 13
#define MBN_NODEOBJ_ENGINEADDRESS   14
#define MBN_NODEOBJ_HWPARENT        15
#define MBN_NODEOBJ_SERVICEREQUEST  16
#define MBN_NODEOBJ_TIMESTAMP       17

/* flags for mbnSendMessage() */
#define MBN_SEND_IGNOREVALID  0x01 /* send the message regardless of our valid bit */
#define MBN_SEND_FORCEADDR    0x02 /* don't overwrite the AddressTo field with our address */
#define MBN_SEND_NOCREATE     0x04 /* don't try to parse the structs, just send the "buffer" member */
#define MBN_SEND_RAWDATA      0x08 /* don't even create the header, just send the "raw" member */
#define MBN_SEND_ACKNOWLEDGE  0x10 /* require acknowledge, and re-send message after a timeout */
#define MBN_SEND_FORCEID      0x20 /* don't overwrite MessageID field */




/*
 *    M A C R O S
 *   (only used internally, because we're lazy)
 */

#ifdef MBNP_BUILD
# define MBN_ADDR_EQ(a, b) ( \
    ((a)->ManufacturerID     == 0 || (b)->ManufacturerID     == 0 || (a)->ManufacturerID     == (b)->ManufacturerID)  && \
    ((a)->ProductID          == 0 || (b)->ProductID          == 0 || (a)->ProductID          == (b)->ProductID)       && \
    ((a)->UniqueIDPerProduct == 0 || (b)->UniqueIDPerProduct == 0 || (a)->UniqueIDPerProduct == (b)->UniqueIDPerProduct) \
  )
/* these assume mbn is a pointer to a struct mbn_handler */
# define LCK()  pthread_mutex_lock(  (pthread_mutex_t *)mbn->mbn_mutex)
# define ULCK() pthread_mutex_unlock((pthread_mutex_t *)mbn->mbn_mutex)
#endif




/*
 *    E R R O R   H A N D L I N G
 */

enum mbn_error {
  MBN_ERROR_NO_INTERFACE,
  MBN_ERROR_INVALID_ADDR,
  MBN_ERROR_CREATE_MESSAGE,
  MBN_ERROR_PARSE_MESSAGE,
  MBN_ERROR_ITF_READ,
  MBN_ERROR_ITF_WRITE
};




/*
 *    F O R W A R D   D E C L A R A T I O N S  (for structs)
 */

/* unions are a bit special, it seems... */
union mbn_data {
  long SInt;
  float Float;
  unsigned long UInt;
  unsigned long State;
  unsigned char Bits[8];
  unsigned char *Octets;
  char *Error;
  struct mbn_object *Info;
};

struct mbn_node_info;
struct mbn_object;
struct mbn_interface;
struct mbn_message_address;
struct mbn_message_object;
struct mbn_message;
struct mbn_msgqueue;
struct mbn_address_node;
struct mbn_handler;




/*
 *    C A L L B A C K   F U N C T I O N   P R O T O T Y P E S
 */

/* general */
typedef void(*mbn_cb_Error)(struct mbn_handler *, int, char *);
typedef void(*mbn_cb_OnlineStatus)(struct mbn_handler *, unsigned long, char);
typedef int(*mbn_cb_NameChange)(struct mbn_handler *, char *);
typedef int(*mbn_cb_DefaultEngineAddrChange)(struct mbn_handler *, unsigned long);
typedef void(*mbn_cb_SynchroniseDateTime)(struct mbn_handler *, time_t);
typedef void(*mbn_cb_AddressTableChange)(struct mbn_handler *, struct mbn_address_node *, struct mbn_address_node *);
typedef void(*mbn_cb_WriteLogMessage)(struct mbn_handler *, char *);

/* messages */
typedef void(*mbn_cb_AcknowledgeTimeout)(struct mbn_handler *, struct mbn_message *);
typedef void(*mbn_cb_AcknowledgeReply)(struct mbn_handler *, struct mbn_message *, struct mbn_message *, int);
typedef int(*mbn_cb_ReceiveMessage)(struct mbn_handler *, struct mbn_message *);

/* objects */
typedef int(*mbn_cb_SetActuatorData)(struct mbn_handler *, unsigned short, union mbn_data);
typedef int(*mbn_cb_GetSensorData)(struct mbn_handler *, unsigned short, union mbn_data *);
typedef void(*mbn_cb_ObjectFrequencyChange)(struct mbn_handler *, unsigned short, unsigned char);
typedef int(*mbn_cb_ObjectInformationResponse)(struct mbn_handler *, struct mbn_message *, unsigned short, struct mbn_object *);
typedef int(*mbn_cb_ObjectFrequencyResponse)(struct mbn_handler *, struct mbn_message *, unsigned short, unsigned char);
typedef int(*mbn_cb_ObjectDataResponse)(struct mbn_handler *, struct mbn_message *, unsigned short, unsigned char, union mbn_data);
typedef void(*mbn_cb_ObjectError)(struct mbn_handler *, struct mbn_message *, unsigned short, char *);

/* interfaces */
typedef int(*mbn_cb_InitInterface)(struct mbn_interface *, char *);
typedef void(*mbn_cb_StopInterface)(struct mbn_interface *);
typedef void(*mbn_cb_FreeInterface)(struct mbn_interface *);
typedef void(*mbn_cb_FreeInterfaceAddress)(struct mbn_interface *, void *);
typedef int(*mbn_cb_InterfaceTransmit)(struct mbn_interface *, unsigned char *, int, void *, char *);




/*
 *    S T R U C T   D E F I N I T I O N S
 */

/* All information required for the default objects of a node */
struct mbn_node_info {
  unsigned int MambaNetAddr;
  unsigned char Services;
  char Description[64];
  char Name[32];
  unsigned short ManufacturerID, ProductID, UniqueIDPerProduct;
  unsigned char HardwareMajorRevision, HardwareMinorRevision;
  unsigned char FirmwareMajorRevision, FirmwareMinorRevision;
  unsigned char FPGAFirmwareMajorRevision, FPGAFirmwareMinorRevision;
  unsigned short NumberOfObjects;
  unsigned int DefaultEngineAddr;
  unsigned short HardwareParent[3];
  unsigned char ServiceRequest;
};

/* Information about a custom object */
struct mbn_object {
  char Description[32];
  unsigned char Services;
  unsigned char UpdateFrequency;
  unsigned char SensorType;
  unsigned char SensorSize;
  union mbn_data SensorMin, SensorMax;
  union mbn_data SensorData;
  unsigned char ActuatorType;
  unsigned char ActuatorSize;
  union mbn_data ActuatorMin, ActuatorMax;
  union mbn_data ActuatorDefault;
  union mbn_data ActuatorData;
  unsigned int EngineAddr;
  /* used internally */
  unsigned int timeout;
  char changed;
};

/* HW interfaces */
struct mbn_interface {
  void *data;
  mbn_cb_InitInterface cb_init;
  mbn_cb_StopInterface cb_stop;
  mbn_cb_FreeInterface cb_free;
  mbn_cb_FreeInterfaceAddress cb_free_addr;
  mbn_cb_InterfaceTransmit cb_transmit;
  struct mbn_handler *mbn;
};

/* Ethernet interfaces */
#ifdef MBN_IF_ETHERNET
struct mbn_if_ethernet {
  struct mbn_if_ethernet *next;
  char *desc;
  char *name;
  unsigned char addr[6];
};
#endif

/* Address message */
struct mbn_message_address {
  unsigned char Action;
  unsigned short ManufacturerID, ProductID, UniqueIDPerProduct;
  unsigned long MambaNetAddr, EngineAddr;
  unsigned char Services;
};

/* Object message */
struct mbn_message_object {
  unsigned short Number;
  unsigned char Action;
  unsigned char DataType;
  unsigned char DataSize;
  union mbn_data Data;
};

/* MambaNet Message */
struct mbn_message {
  unsigned char AcknowledgeReply;
  unsigned long AddressTo, AddressFrom;
  unsigned int MessageID;
  unsigned short MessageType;
  union {
    struct mbn_message_address Address;
    struct mbn_message_object Object;
  } Message;
  /* used internally */
  unsigned char *raw;
  int rawlength;
  unsigned char buffer[98];
  int bufferlength;
};

/* Message queue for acknowledges */
struct mbn_msgqueue {
  unsigned int id;
  struct mbn_message msg;
  int retries; /* -1 = acknowledged */
  struct mbn_msgqueue *next;
};

/* Address table node */
struct mbn_address_node {
  unsigned short ManufacturerID, ProductID, UniqueIDPerProduct;
  unsigned long MambaNetAddr, EngineAddr;
  unsigned char Services;
  int Alive;
  void *ifaddr;
  char used;
};

/* The main handler */
struct mbn_handler {
  struct mbn_node_info node;
  struct mbn_interface *itf;
  int addrsize;
  struct mbn_address_node *addresses;
  struct mbn_object *objects;
  struct mbn_msgqueue *queue;
  int pongtimeout;
  /* pthread objects */
  void *timeout_thread, *throttle_thread, *msgqueue_thread;
  char timeout_run, throttle_run, msgqueue_run;
  void *mbn_mutex;
  /* callbacks */
  mbn_cb_ReceiveMessage cb_ReceiveMessage;
  mbn_cb_AddressTableChange cb_AddressTableChange;
  mbn_cb_WriteLogMessage cb_WriteLogMessage;
  mbn_cb_OnlineStatus cb_OnlineStatus;
  mbn_cb_NameChange cb_NameChange;
  mbn_cb_DefaultEngineAddrChange cb_DefaultEngineAddrChange;
  mbn_cb_SetActuatorData cb_SetActuatorData;
  mbn_cb_GetSensorData cb_GetSensorData;
  mbn_cb_ObjectFrequencyChange cb_ObjectFrequencyChange;
  mbn_cb_ObjectInformationResponse cb_ObjectInformationResponse;
  mbn_cb_ObjectFrequencyResponse cb_ObjectFrequencyResponse;
  mbn_cb_ObjectDataResponse cb_SensorDataResponse;
  mbn_cb_ObjectDataResponse cb_SensorDataChanged;
  mbn_cb_ObjectDataResponse cb_ActuatorDataResponse;
  mbn_cb_ObjectError cb_ObjectError;
  mbn_cb_Error cb_Error;
  mbn_cb_AcknowledgeTimeout cb_AcknowledgeTimeout;
  mbn_cb_AcknowledgeReply cb_AcknowledgeReply;
  mbn_cb_SynchroniseDateTime cb_SynchroniseDateTime;
};




/*
 *     F U N C T I O N   P R O T O T Y P E S
 */

#ifdef __cplusplus
extern "C" {
#endif

/* mbn.c */
struct mbn_handler * MBN_EXPORT mbnInit(struct mbn_node_info *, struct mbn_object *, struct mbn_interface *, char *);
void MBN_EXPORT mbnStartInterface(struct mbn_interface *itf, char *err);
void MBN_EXPORT mbnFree(struct mbn_handler *);
void MBN_EXPORT mbnProcessRawMessage(struct mbn_interface *, unsigned char *, int, void *);
void MBN_EXPORT mbnSendMessage(struct mbn_handler *, struct mbn_message *, int);
void MBN_EXPORT mbnUpdateNodeName(struct mbn_handler *, char *);
void MBN_EXPORT mbnUpdateEngineAddr(struct mbn_handler *, unsigned long);
void MBN_EXPORT mbnUpdateServiceRequest(struct mbn_handler *, char);
//void MBN_EXPORT mbnWriteLogMessage(struct mbn_interface *, const char *fmt, ...);
const char *MBN_EXPORT mbnVersion();

/* if_*.c */
#ifdef MBN_IF_ETHERNET
struct mbn_interface * MBN_EXPORT mbnEthernetOpen(char *, char *);
struct mbn_if_ethernet * MBN_EXPORT mbnEthernetIFList(char *);
void MBN_EXPORT mbnEthernetIFFree(struct mbn_if_ethernet *);
char MBN_EXPORT mbnEthernetMIILinkStatus(struct mbn_interface *, char *);
#endif
#ifdef MBN_IF_TCP
struct mbn_interface * MBN_EXPORT mbnTCPOpen(char *, char *, char *, char *, char *);
#endif
#ifdef MBN_IF_UDP
struct mbn_interface * MBN_EXPORT mbnUDPOpen(char *, char *, char *, char *);
#endif

/* address.c */
void MBN_EXPORT mbnForceAddress(struct mbn_handler *, unsigned long);
void MBN_EXPORT mbnSendPingRequest(struct mbn_handler *, unsigned long);
struct mbn_address_node * MBN_EXPORT mbnNodeStatus(struct mbn_handler *, unsigned long);
struct mbn_address_node * MBN_EXPORT mbnNextNode(struct mbn_handler *, struct mbn_address_node *);

/* object.c */
void MBN_EXPORT mbnUpdateSensorData(struct mbn_handler *, unsigned short, union mbn_data);
void MBN_EXPORT mbnUpdateActuatorData(struct mbn_handler *, unsigned short, union mbn_data);
void MBN_EXPORT mbnGetSensorData(struct mbn_handler *, unsigned long, unsigned short, char);
void MBN_EXPORT mbnGetActuatorData(struct mbn_handler *, unsigned long, unsigned short, char);
void MBN_EXPORT mbnGetObjectInformation(struct mbn_handler *, unsigned long, unsigned short, char);
void MBN_EXPORT mbnGetObjectFrequency(struct mbn_handler *, unsigned long, unsigned short, char);
void MBN_EXPORT mbnSetActuatorData(struct mbn_handler *, unsigned long, unsigned short, unsigned char, unsigned char, union mbn_data, char);
void MBN_EXPORT mbnSetObjectFrequency(struct mbn_handler *, unsigned long, unsigned short, unsigned char, char);

#ifdef __cplusplus
}
#endif




/*
 *     M A C R O S
 */

/* Things that look like functions to the application but are secretly macros.
 * (This is both faster because no extra functions have to be called, and makes
 *  the library smaller because no extra functions have to be exported)
 * These macros may still be replaced with proper functions when needed in the future.
 */
#define mbnInterfaceReadError(itf, err) if((itf)->mbn->cb_Error) { (itf)->mbn->cb_Error((itf)->mbn, MBN_ERROR_ITF_READ, (err)); }
#define mbnSetInterface(mbn, itf)                          ((mbn)->interface = interface)
#define mbnSetReceiveMessageCallback(mbn, func)            ((mbn)->cb_ReceiveMessage = func)
#define mbnUnsetReceiveMessageCallback(mbn)                ((mbn)->cb_ReceiveMessage = NULL)
#define mbnSetAddressTableChangeCallback(mbn, func)        ((mbn)->cb_AddressTableChange = func)
#define mbnUnsetAddressTableChangeCallback(mbn)            ((mbn)->cb_AddressTableChange = NULL)
#define mbnSetWriteLogMessageCallback(mbn, func)           ((mbn)->cb_WriteLogMessage = func)
#define mbnUnsetWriteLogMessageCallback(mbn)               ((mbn)->cb_WriteLogMessage = NULL)
#define mbnSetOnlineStatusCallback(mbn, func)              ((mbn)->cb_OnlineStatus = func)
#define mbnUnsetOnlineStatusCallback(mbn)                  ((mbn)->cb_OnlineStatus = NULL)
#define mbnSetNameChangeCallback(mbn, func)                ((mbn)->cb_NameChange = func)
#define mbnUnsetNameChangeCallback(mbn)                    ((mbn)->cb_NameChange = NULL)
#define mbnSetDefaultEngineAddrChangeCallback(mbn, func)   ((mbn)->cb_DefaultEngineAddrChange = func)
#define mbnUnsetDefaultEngineAddrChangeCallback(mbn)       ((mbn)->cb_DefaultEngineAddrChange = NULL)
#define mbnSetSetActuatorDataCallback(mbn, func)           ((mbn)->cb_SetActuatorData = func)
#define mbnUnsetSetActuatorDataCallback(mbn)               ((mbn)->cb_SetActuatorData = NULL)
#define mbnSetGetSensorDataCallback(mbn, func)             ((mbn)->cb_GetSensorData = func)
#define mbnUnsetGetSensorDataCallback(mbn)                 ((mbn)->cb_GetSensorData = NULL)
#define mbnSetObjectFrequencyChangeCallback(mbn, func)     ((mbn)->cb_ObjectFrequencyChange = func)
#define mbnUnsetObjectFrequencyChangeCallback(mbn)         ((mbn)->cb_ObjectFrequencyChange = NULL)
#define mbnSetObjectInformationResponseCallback(mbn, func) ((mbn)->cb_ObjectInformationResponse = func)
#define mbnUnsetObjectInformationResponseCallback(mbn)     ((mbn)->cb_ObjectInformationResponse = NULL)
#define mbnSetObjectFrequencyResponseCallback(mbn, func)   ((mbn)->cb_ObjectFrequencyResponse = func)
#define mbnUnsetObjectFrequencyResponseCallback(mbn)       ((mbn)->cb_ObjectFrequencyResponse = NULL)
#define mbnSetSensorDataResponseCallback(mbn, func)        ((mbn)->cb_SensorDataResponse = func)
#define mbnUnsetSensorDataResponseCallback(mbn)            ((mbn)->cb_SensorDataResponse = NULL)
#define mbnSetSensorDataChangedCallback(mbn, func)         ((mbn)->cb_SensorDataChanged = func)
#define mbnUnsetSensorDataChangedCallback(mbn)             ((mbn)->cb_SensorDataChanged = NULL)
#define mbnSetActuatorDataResponseCallback(mbn, func)      ((mbn)->cb_ActuatorDataResponse = func)
#define mbnUnsetActuatorDataResponseCallback(mbn)          ((mbn)->cb_ActuatorDataResponse = NULL)
#define mbnSetObjectErrorCallback(mbn, func)               ((mbn)->cb_ObjectError = func)
#define mbnUnsetObjectErrorCallback(mbn)                   ((mbn)->cb_ObjectError = NULL)
#define mbnSetErrorCallback(mbn, func)                     ((mbn)->cb_Error = func)
#define mbnUnsetErrorCallback(mbn)                         ((mbn)->cb_Error = NULL)
#define mbnSetAcknowledgeTimeoutCallback(mbn, func)        ((mbn)->cb_AcknowledgeTimeout = func)
#define mbnUnsetAcknowledgeTimeoutCallback(mbn)            ((mbn)->cb_AcknowledgeTimeout = NULL)
#define mbnSetAcknowledgeReplyCallback(mbn, func)          ((mbn)->cb_AcknowledgeReply = func)
#define mbnUnsetAcknowledgeReplyCallback(mbn)              ((mbn)->cb_AcknowledgeReply = NULL)
#define mbnSetSynchroniseDateTimeCallback(mbn, func)       ((mbn)->cb_SynchroniseDateTime = func)
#define mbnUnsetSynchroniseDateTimeCallback(mbn)           ((mbn)->cb_SynchroniseDateTime = NULL)




/*
 *     O B J E C T   L I S T   C R E A T I O N
 */

#ifdef MBN_VARARG
#include <stdarg.h>
#include <string.h>

/* One VA_ARG functions embedded in the .h, as exporting them
 *  from .dlls be a bit problematic on some systems */

struct mbn_object MBN_OBJ(char *desc, ...) {
  struct mbn_object obj;
  va_list va;
  va_start(va, desc);

  /* basic info */
  memcpy((void *)obj.Description, (void *)desc, strlen((char *)desc)+1);
  obj.EngineAddr = 0;
  obj.UpdateFrequency = 0;

  /* sensor */
  obj.SensorType = (unsigned char) va_arg(va, int);
  switch(obj.SensorType) {
    case MBN_DATATYPE_UINT:
    case MBN_DATATYPE_STATE:
      obj.UpdateFrequency = (unsigned short) va_arg(va, unsigned long);
      obj.SensorSize = (unsigned char) va_arg(va, int);
      obj.SensorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.SensorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.SensorData.UInt = (unsigned long) va_arg(va, unsigned long);
      break;
    case MBN_DATATYPE_SINT:
      obj.UpdateFrequency = (unsigned short) va_arg(va, unsigned long);
      obj.SensorSize = (unsigned char) va_arg(va, int);
      obj.SensorMin.SInt  = (long) va_arg(va, long);
      obj.SensorMax.SInt  = (long) va_arg(va, long);
      obj.SensorData.SInt = (long) va_arg(va, long);
      break;
    case MBN_DATATYPE_FLOAT:
      obj.UpdateFrequency = (unsigned short) va_arg(va, unsigned long);
      obj.SensorSize = (unsigned char) va_arg(va, int);
      obj.SensorMin.Float  = (float) va_arg(va, double);
      obj.SensorMax.Float  = (float) va_arg(va, double);
      obj.SensorData.Float = (float) va_arg(va, double);
      break;
    case MBN_DATATYPE_OCTETS:
      obj.UpdateFrequency = (unsigned short) va_arg(va, unsigned long);
      obj.SensorSize = (unsigned char) va_arg(va, int);
      obj.SensorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.SensorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.SensorData.Octets = (unsigned char *) va_arg(va, char *);
      break;
    case MBN_DATATYPE_BITS:
      obj.UpdateFrequency = (unsigned short) va_arg(va, unsigned long);
      obj.SensorSize = (unsigned char) va_arg(va, int);
      obj.SensorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.SensorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      memcpy((void *)obj.SensorData.Bits, (void *)va_arg(va, unsigned char *), obj.SensorSize);
      break;
    default:
      obj.SensorType = MBN_DATATYPE_NODATA;
      obj.SensorSize = 0;
      break;
  }

  /* actuator */
  obj.ActuatorType = (unsigned char) va_arg(va, int);
  switch(obj.ActuatorType) {
    case MBN_DATATYPE_UINT:
    case MBN_DATATYPE_STATE:
      obj.ActuatorSize = (unsigned char) va_arg(va, int);
      obj.ActuatorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorDefault.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorData.UInt = (unsigned long) va_arg(va, unsigned long);
      break;
    case MBN_DATATYPE_SINT:
      obj.ActuatorSize = (unsigned char) va_arg(va, int);
      obj.ActuatorMin.SInt  = (long) va_arg(va, long);
      obj.ActuatorMax.SInt  = (long) va_arg(va, long);
      obj.ActuatorDefault.SInt  = (long) va_arg(va, long);
      obj.ActuatorData.SInt = (long) va_arg(va, long);
      break;
    case MBN_DATATYPE_FLOAT:
      obj.ActuatorSize = (unsigned char) va_arg(va, int);
      obj.ActuatorMin.Float  = (float) va_arg(va, double);
      obj.ActuatorMax.Float  = (float) va_arg(va, double);
      obj.ActuatorDefault.Float  = (float) va_arg(va, double);
      obj.ActuatorData.Float = (float) va_arg(va, double);
      break;
    case MBN_DATATYPE_OCTETS:
      obj.ActuatorSize = (unsigned char) va_arg(va, int);
      obj.ActuatorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorDefault.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorData.Octets = (unsigned char *) va_arg(va, char *);
      break;
    case MBN_DATATYPE_BITS:
      obj.ActuatorSize = (unsigned char) va_arg(va, int);
      obj.ActuatorMin.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorMax.UInt  = (unsigned long) va_arg(va, unsigned long);
      obj.ActuatorDefault.UInt  = (unsigned long) va_arg(va, unsigned long);
      memcpy((void *)obj.ActuatorData.Bits, (void *)va_arg(va, unsigned char *), obj.ActuatorSize);
      break;
    default:
      obj.ActuatorType = MBN_DATATYPE_NODATA;
      obj.ActuatorSize = 0;
      break;
  }
  va_end(va);
  return obj;
}

#endif /* MBN_VARARG */



#endif /* MBN_H */


