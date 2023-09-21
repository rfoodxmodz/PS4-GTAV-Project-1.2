#include <Common.h>
#include "plugin_common.h"

#include <stdint.h>
#include <stdarg.h>


#include "types.h"

#define AF_INET 0x0002

#define IN_ADDR_ANY 0

#define SOCK_STREAM 1
#define SOCK_DGRAM 2

#define SOL_SOCKET 0xFFFF
#define SO_NBIO 0x1200

#define MSG_DONTWAIT 0x80
#define MSG_WAITALL 0x40

#define IPPROTO_TCP 6
#define TCP_NODELAY 1

#define SCE_USER_SERVICE_USER_ID_EVERYONE 254

enum {
	SCE_NET_IPPROTO_IP = 0,
	SCE_NET_IPPROTO_ICMP = 1,
	SCE_NET_IPPROTO_IGMP = 2,
	SCE_NET_IPPROTO_TCP = 6,
	SCE_NET_IPPROTO_UDP = 17,
	SCE_NET_SOL_SOCKET = 0xFFFF
};

enum {
	SCE_NET_SO_REUSEADDR = 0x00000004,
};

enum {
	SCE_NET_ERROR_EINTR = 0x80410104,
};

enum {
	SCE_NET_SOCKET_ABORT_FLAG_RCV_PRESERVATION = 0x00000001,
	SCE_NET_SOCKET_ABORT_FLAG_SND_PRESERVATION = 0x00000002
};

struct in_addr {
	unsigned int s_addr;
};

struct sockaddr_in {
	unsigned char sin_len;
	unsigned char sin_family;
	unsigned short sin_port;
	struct in_addr sin_addr;
	unsigned short sin_vport;
	char sin_zero[6];
};

struct sockaddr {
	unsigned char sin_len;
	unsigned char sa_family;
	char sa_data[14];
};

typedef unsigned int socklen;
typedef void *ScePthread;
typedef void *ScePthreadAttr;

typedef int SceUserServiceUserId;




//sys
//extern int (*sceKernelLoadStartModule)(const char *name, size_t argc, const void *argv, unsigned int flags, int, int);

//notifications
extern int (*sceSysUtilSendSystemNotificationWithText)(int messageType, const char *message);

//message dialogs
#define SCE_COMMON_DIALOG_MAGIC_NUMBER 0xC0D1A109

enum SceCommonDialogStatus {
	SCE_COMMON_DIALOG_STATUS_NONE = 0,
	SCE_COMMON_DIALOG_STATUS_INITIALIZED = 1,
	SCE_COMMON_DIALOG_STATUS_RUNNING = 2,
	SCE_COMMON_DIALOG_STATUS_FINISHED = 3
};

enum SceCommonDialogResult {
	SCE_COMMON_DIALOG_RESULT_OK = 0,
	SCE_COMMON_DIALOG_RESULT_USER_CANCELED = 1,
};

typedef struct SceCommonDialogBaseParam {
	size_t size;
	uint8_t reserved[36];
	uint32_t magic;
} SceCommonDialogBaseParam __attribute__((__aligned__(8)));

enum SceMsgDialogMode {
	SCE_MSG_DIALOG_MODE_USER_MSG = 1,
	SCE_MSG_DIALOG_MODE_PROGRESS_BAR = 2,
	SCE_MSG_DIALOG_MODE_SYSTEM_MSG = 3,
};

enum SceMsgDialogButtonType {
	SCE_MSG_DIALOG_BUTTON_TYPE_OK = 0,
	SCE_MSG_DIALOG_BUTTON_TYPE_YESNO = 1,
	SCE_MSG_DIALOG_BUTTON_TYPE_NONE = 2,
	SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL = 3,
	SCE_MSG_DIALOG_BUTTON_TYPE_WAIT = 5,
	SCE_MSG_DIALOG_BUTTON_TYPE_WAIT_CANCEL = 6,
	SCE_MSG_DIALOG_BUTTON_TYPE_YESNO_FOCUS_NO = 7,
	SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL_FOCUS_CANCEL = 8,
	SCE_MSG_DIALOG_BUTTON_TYPE_2BUTTONS = 9,
};

enum SceMsgDialogProgressBarType {
	SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE = 0,
	SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE_CANCEL = 1,
};

enum SceMsgDialogSystemMessageType {
	SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_EMPTY_STORE = 0,
	SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_CHAT_RESTRICTION = 1,
	SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_UGC_RESTRICTION = 2,
	SCE_MSG_DIALOG_SYSMSG_TYPE_CAMERA_NOT_CONNECTED = 4,
	SCE_MSG_DIALOG_SYSMSG_TYPE_WARNING_PROFILE_PICTURE_AND_NAME_NOT_SHARED = 5,
};

struct SceMsgDialogButtonsParam {
	const char *msg1;
	const char *msg2;
	char reserved[32];
};

struct SceMsgDialogUserMessageParam {
	SceMsgDialogButtonType buttonType;
	int : 32;
	const char *msg;
	SceMsgDialogButtonsParam *buttonsParam;
	char reserved[24];
};

struct SceMsgDialogProgressBarParam {
	SceMsgDialogProgressBarType barType;
	int : 32;
	const char *msg;
	char reserved[64];
};

struct SceMsgDialogSystemMessageParam {
	SceMsgDialogSystemMessageType sysMsgType;
	char reserved[32];
};

struct SceMsgDialogParam {
	SceCommonDialogBaseParam baseParam;
	size_t size;
	SceMsgDialogMode mode;
	int : 32;
	SceMsgDialogUserMessageParam *userMsgParam;
	SceMsgDialogProgressBarParam *progBarParam;
	SceMsgDialogSystemMessageParam *sysMsgParam;
	SceUserServiceUserId userId;
	char reserved[40];
	int : 32;
};

extern int (*sceCommonDialogInitialize)(void);
extern int (*sceMsgDialogInitialize)(void);
extern int (*sceMsgDialogOpen)(const SceMsgDialogParam *param);
extern SceCommonDialogStatus (*sceMsgDialogUpdateStatus)(void);
extern int (*sceMsgDialogTerminate)(void);

//ime dialogs
enum SceImeType {
	SCE_IME_TYPE_DEFAULT = 0,
	SCE_IME_TYPE_BASIC_LATIN = 1,
	SCE_IME_TYPE_URL = 2,
	SCE_IME_TYPE_MAIL = 3,
	SCE_IME_TYPE_NUMBER = 4,
};

enum SceImeEnterLabel {
	SCE_IME_ENTER_LABEL_DEFAULT = 0,
	SCE_IME_ENTER_LABEL_SEND = 1,
	SCE_IME_ENTER_LABEL_SEARCH = 2,
	SCE_IME_ENTER_LABEL_GO = 3,
};

enum SceImeInputMethod {
	SCE_IME_INPUT_METHOD_DEFAULT = 0,
};

typedef int (*SceImeTextFilter)(wchar_t *outText, uint32_t *outTextLength, const wchar_t *srcText, uint32_t srcTextLength);

enum SceImeVerticalAlignment {
	SCE_IME_VALIGN_TOP = 0,
	SCE_IME_VALIGN_CENTER = 1,
	SCE_IME_VALIGN_BOTTOM = 2,
};

enum SceImeHorizontalAlignment {
	SCE_IME_HALIGN_LEFT = 0,
	SCE_IME_HALIGN_CENTER = 1,
	SCE_IME_HALIGN_RIGHT = 2,
};

enum SceImeDialogStatus {
	SCE_IME_DIALOG_STATUS_NONE = 0,
	SCE_IME_DIALOG_STATUS_RUNNING = 1,
	SCE_IME_DIALOG_STATUS_FINISHED = 2,
};

enum SceImeDialogEndStatus {
	SCE_IME_DIALOG_END_STATUS_OK = 0,
	SCE_IME_DIALOG_END_STATUS_USER_CANCELED = 1,
	SCE_IME_DIALOG_END_STATUS_ABORTED = 2,
};

struct SceImeDialogResult {
	SceImeDialogEndStatus endstatus;
	int8_t reserved[12];
};

struct SceImeDialogParam {
	SceUserServiceUserId userId;
	SceImeType type;
	uint64_t supportedLanguages;
	SceImeEnterLabel enterLabel;
	SceImeInputMethod inputMethod;
	SceImeTextFilter filter;
	uint32_t option;
	uint32_t maxTextLength;
	wchar_t *inputTextBuffer;
	float posx;
	float posy;
	SceImeHorizontalAlignment horizontalAlignment;
	SceImeVerticalAlignment verticalAlignment;
	const wchar_t *placeholder;
	const wchar_t *title;
	int8_t reserved[16];
};

extern int (*sceImeDialogGetResult)(SceImeDialogResult *result);
extern int (*sceImeDialogInit)(const SceImeDialogParam *param, void *extended);
extern SceImeDialogStatus (*sceImeDialogGetStatus)(void);
extern int (*sceImeDialogTerm)(void);

//web dialogs
#define SCE_WEB_BROWSER_DIALOG_COOKIE_URL_SIZE (2048)
#define SCE_WEB_BROWSER_DIALOG_COOKIE_DATA_SIZE (4096)

struct SceWebBrowserDialogSetCookieParam {
	size_t size;
	const char *url;
	const char *cookie;
	char reserved[256];
};

enum SceWebBrowserDialogMode {
	SCE_WEB_BROWSER_DIALOG_MODE_DEFAULT = 1,
	SCE_WEB_BROWSER_DIALOG_MODE_CUSTOM = 2,
};

struct SceWebBrowserDialogWebViewParam {
	size_t size;
	uint32_t option;
	char reserved[256];
	int : 32;
};

typedef int SceWebBrowserCallbackParamType;
struct SceWebBrowserDialogCallbackInitParam {
	size_t size;
	SceWebBrowserCallbackParamType type;
	int : 32;
	const char *data;
	char reserved[32];
};

struct SceWebBrowserDialogImeParam {
	size_t size;
	uint32_t option;
	char reserved[256];
	int : 32;
};

struct SceWebBrowserDialogParam {
	SceCommonDialogBaseParam baseParam;
	size_t size;
	SceWebBrowserDialogMode mode;
	SceUserServiceUserId userId;
	const char *url;
	SceWebBrowserDialogCallbackInitParam *callbackInitParam;
	uint16_t width;
	uint16_t height;
	uint16_t positionX;
	uint16_t positionY;
	uint32_t parts;
	uint16_t headerWidth;
	uint16_t headerPositionX;
	uint16_t headerPositionY;
	short : 16;
	uint32_t control;
	SceWebBrowserDialogImeParam *imeParam;
	SceWebBrowserDialogWebViewParam *webviewParam;
	uint32_t animation;
	char reserved[202];
	short : 16;
};

extern int (*sceWebBrowserDialogInitialize)(void);
extern int (*sceWebBrowserDialogTerminate)(void);
extern int (*sceWebBrowserDialogOpen)(const SceWebBrowserDialogParam *param);
extern SceCommonDialogStatus (*sceWebBrowserDialogUpdateStatus)(void);
extern int (*sceWebBrowserDialogSetCookie)(const SceWebBrowserDialogSetCookieParam *param);

//user service
struct SceUserServiceLoginUserIdList {
	SceUserServiceUserId userId[4];
};

extern int (*sceUserServiceGetInitialUser)(SceUserServiceUserId *userId);
extern int (*sceUserServiceGetUserName)(const SceUserServiceUserId userId, char *userName, const size_t size);
extern int (*sceUserServiceGetLoginUserIdList)(SceUserServiceLoginUserIdList *userIdList);

//gamepad
#define SCE_PAD_MAX_TOUCH_NUM 2
#define SCE_PAD_MAX_DEVICE_UNIQUE_DATA_SIZE 12

#define SCE_PAD_MAX_X_COORDINATE 1919
#define SCE_PAD_MAX_Y_COORDINATE 941


struct ScePadAnalogStick {
	uint8_t x;
	uint8_t y;
};

struct ScePadAnalogButtons {
	uint8_t l2;
	uint8_t r2;
	uint8_t padding[2];
};

struct SceFQuaternion {
	float x, y, z, w;
};

struct SceFVector3 {
	float x, y, z;
};

struct ScePadTouch {
	uint16_t x;
	uint16_t y;
	uint8_t id;
	uint8_t reserve[3];
};

struct ScePadTouchData {
	uint8_t touchNum;
	uint8_t reserve[3];
	uint32_t reserve1; //was uint8_t
	ScePadTouch touch[SCE_PAD_MAX_TOUCH_NUM];
};

struct ScePadExtensionUnitData {
	uint32_t extensionUnitId;
	uint8_t reserve[1];
	uint8_t dataLength;
	uint8_t data[10];
};

struct ScePadData {
	uint32_t buttons;
	ScePadAnalogStick leftStick;
	ScePadAnalogStick rightStick;
	ScePadAnalogButtons analogButtons;
	SceFQuaternion orientation;
	SceFVector3 acceleration;
	SceFVector3 angularVelocity;
	ScePadTouchData touchData;
	bool connected;
	uint64_t timestamp;
	ScePadExtensionUnitData extensionUnitData;
	uint8_t connectedCount;
	uint8_t reserve[2];
	uint8_t deviceUniqueDataLen;
	uint8_t deviceUniqueData[SCE_PAD_MAX_DEVICE_UNIQUE_DATA_SIZE];
};




#define O_RDONLY	0x0000
#define O_WRONLY	0x0001
#define O_RDWR		0x0002
#define O_ACCMODE	0x0003
#define O_NONBLOCK	0x0004	// no delay
#define O_APPEND	0x0008	// set append mode
#define O_CREAT		0x0200	// create if nonexistent
#define O_TRUNC		0x0400	// truncate to zero length
#define O_EXCL		0x0800	// error if already exists

//libc
extern void *(*mmap)(void *addr, size_t len, int prot, int	flags, int fd, off_t offset);
//extern int(*access)(const char *path, int mode);
extern int(*open)(const char *path, int flags, ...);
extern int(*isspace)(int c);
extern int(*isupper)(int c);
extern int(*islower)(int c);
extern int(*toupper)(int c);
extern int(*tolower)(int c);


int getpid();
//int open(char *path, int flags, int mode);
void *sys_mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
void *sys_munmap(void *addr, size_t len);

void initImports();

