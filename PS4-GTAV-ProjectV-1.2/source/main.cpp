#include <stdint.h>
#include <stdarg.h>
#include "detour.h"
#include "utility.h"
#include "hooks.h"
#include "imports.h"
#include "types.h"
#define GOLDHEN_PATH_ (const char*) GOLDHEN_PATH
#define BASE_PATH_PATCH (const char*) GOLDHEN_PATH_ "/patches"
#define BASE_PATH_PATCH_SETTINGS (const char*) BASE_PATH_PATCH "/settings"
#define PLUGIN_NAME (const char*) "game_patch"
#define PLUGIN_DESC (const char*) "GTA V Modding"
#define PLUGIN_AUTH (const char*) "rfoodxmodz"
#define PLUGIN_VER 0x110 // 1.10

#define NO_ASLR_ADDR 0x00400000
long APP_BASE = 0x400000;

attr_public const char *g_pluginName = PLUGIN_NAME;
attr_public const char *g_pluginDesc = PLUGIN_DESC;
attr_public const char *g_pluginAuth = PLUGIN_AUTH;
attr_public u32 g_pluginVersion = PLUGIN_VER;

char titleid[16] = {0};
char game_elf[32] = {0};
char game_prx[MAX_PATH_] = {0};
char game_ver[8] = {0};

u64 module_base = 0;
u32 module_size = 0;
// unused for now
u64 PRX_module_base = 0;
u32 PRX_module_size = 0;
struct proc_info procInfo;

// https://github.com/bucanero/apollo-ps4/blob/a530cae3c81639eedebac606c67322acd6fa8965/source/orbis_jbc.c#L62
int get_module_info(OrbisKernelModuleInfo moduleInfo, const char* name, uint64_t *base, uint32_t *size)
{
    OrbisKernelModule handles[256];
    size_t numModules;
    int ret = 0;
    ret = sceKernelGetModuleList(handles, sizeof(handles), &numModules);
    if (ret)
    {
        final_printf("sceKernelGetModuleList (0x%08x)\n", ret);
        return ret;
    }
    final_printf("numModules: %li\n", numModules);
    for (size_t i = 0; i < numModules; ++i)
    {
        ret = sceKernelGetModuleInfo(handles[i], &moduleInfo);
        final_printf("ret 0x%x\n", ret);
        final_printf("module %li\n", i);
        final_printf("name: %s\n", moduleInfo.name);
        final_printf("start: 0x%lx\n", (uint64_t)moduleInfo.segmentInfo[0].address);
        final_printf("size: %u (0x%x)\n", moduleInfo.segmentInfo[0].size, moduleInfo.segmentInfo[0].size);
        if (ret)
        {
            final_printf("sceKernelGetModuleInfo (%X)\n", ret);
            return ret;
        }

        if (strcmp(moduleInfo.name, name) == 0 || name[0] == '0')
        {
            if (base)
                *base = (uint64_t)moduleInfo.segmentInfo[0].address;

            if (size)
                *size = moduleInfo.segmentInfo[0].size;
            return 1;
        }
    }
    return 0;
}

void* project_thread(void* args)
{
  
    u64  gfx_addr = (uint64_t)PatternScan(0x1A00000, 0x2500000, "55 48 89 E5 41 57 41 56 53 50 49 89 D7 49 89 F6 48 8B ? ? ? ? 89 C1 FF ? ?");
   //patch_data1("byte", 0x252C780 + module_base, "\xC3", 1, NULL);
  // u8 arr8[1];
   //arr8[0] = 0xC3;
  // memcpy_p(0x252C780 + module_base, "\xC3", 1);
   // memcpy_p(0x252C780 + module_base, "\xC3", 1);
    memcpy_p((gfx_addr), "\x55\x48\x89\xE5\x41\x57\x41\x56\x53\x50\x49\x89\xD7\x49\x89\xF6", 16);
    Hooks::gfxLoader_Stub = (Hooks::gfxLoader_t)DetourFunction((gfx_addr), (void *)Hooks::gfxLoader_hook, 16);
	

	
	//XML LOADER
	u64 xml_omt_addr = (uint64_t)PatternScan(0x1F00000, 0x3250000, "55 48 89 E5 41 57 41 56 41 54 53 48 81 EC 10 01 00 00 49 89 CC");
	memcpy_p((xml_omt_addr), "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x54\x53\x48\x81\xEC\x10\x01\x00\x00\x49\x89\xCC", 21);
	Hooks::xml_omt_Loader_Stub = (Hooks::xml_omt_Loader_t)DetourFunction((xml_omt_addr), (void *)Hooks::xml_omt_Loader_hook, 21);
	
	
	
	// [GXT2 LOADER] 
	
	//char msgB[255];
	u64 gxt2_addr = (uint64_t)PatternScan(0x2100000, 0x2700000, "95 30 FF FF FF 4C 8B ? ? ? ? ? 49 8B ? 48 89 45 E8 C5 ? 57 C0 C5 F8 29 45 D0 48 C7 45 E0 00 00 00 00 48 8D 85 20 FF FF FF 48 89 45 E0 48 8D 45 10 48 89 45 D8 C7 45 D4 30 00 00 00 C7 45 D0 10 00 00 00 48 8D 4D D0 48 89 DF BE 40 00 00") - 0x60;
	//sprintf(msgB, "gxt2_addr: %llx", gxt2_addr);
	//sceSysUtilSendSystemNotificationWithText(222, msgB);
	
	memcpy_p((gxt2_addr), "\x55\x48\x89\xE5\x41\x56\x53\x48\x81\xEC\xD0\x00\x00\x00\x49\x89\xF2\x48\x89\xFB", 20);
	Hooks::GXT2_Stub = (Hooks::GXT2_t)DetourFunction((gxt2_addr), (void *)Hooks::GXT2_hook, 20);
	//char buffe[255];


	//[DATA LOADER] 
	Hooks::SUB_19E03E0_ADDR = (int64_t)PatternScan(0x1900000, 0x2200000, "55 48 89 E5 41 56 53 48 81 EC 10 01 00 00 48 89 D0");
	Hooks::SUB_19E0200_ADDR = (int64_t)PatternScan(0x1900000, 0x2200000, "55 48 89 E5 41 57 41 56 41 55 41 54 53 48 81 EC 08 01 00 00 49 89 D6 49 89 ? 49 89 ? 48");
	//sprintf(buffe, "SUB_19E0200_ADDR: 0x%llx", Hooks::SUB_19E0200_ADDR);
	//sceSysUtilSendSystemNotificationWithText(222, buffe);
	/* [OMT | METADATA LOADER] */

	
/*	u64 addr = 49 C7 06 00 00 00 00 41 C7 46 08  00 00 00 00 48 8D 3D + 0xF
u32 instructionBytes =  *(u32*)(addr + 0x12);

u32 v_file_pointer = instructionBytes + (addr + 7);
*/
	
	u64 v_instruction_addr = (int64_t)PatternScan(0x425000, 0x452000, "49 C7 06 00 00 00 00 41 C7 46 08 00 00 00 00 48 8D 3D") + 0xF;
	u64 instructionBytes =  *(u32*)(v_instruction_addr + 0x3);
	Hooks::v_gameDir = instructionBytes + v_instruction_addr + 7;
	//sprintf(buffe, "v_gameDir: 0x%llx", Hooks::v_gameDir);
	//sceSysUtilSendSystemNotificationWithText(222, buffe);
	WriteJump((uint64_t)PatternScan(0xE00000, 0x1200000, "48 89 F0 48 89 FE 40 B7 01 48 85 C0 74 4D 45 30"), (uint64_t)Hooks::DataFunc_hook);
	
	
u64 omt_addr = (uint64_t)PatternScan(0x1200000, 0x3000000, "55 48 89 E5 41 57 41 56 41 55 41 54 53 48 81 EC 08 01 00 00 49 89 D6 49 89 ? 49 89 ? 48");
memcpy_p(omt_addr,"\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xEC\x08\x01\x00\x00", 20);
Hooks::omtLoader_Stub = (Hooks::omtLoader_t)DetourFunction((omt_addr), (void *)Hooks::omtLoader_hook, 20);
	
   // [XML | METADATA LOADER] 
   
   
	u32 xml_func_inst[0x301];
	u64 xml_addr = (uint64_t)PatternScan(0x1800000, 0x3000000, "E8 ? ? 05 00 88 D8 48  83 C4 18 5B 41 5C 41 5D 41 5E 41 5F 5D C3 66 2E  0F 1F 84 00 00 00 00 00") + 0x20;
	for(int i = 0; i <= 0x256; i++) {
	xml_func_inst[i] = *(u32*)(xml_addr + (i * 4));
	sceKernelMprotect((void*)(xml_addr + (i * 4)), 4, VM_PROT_ALL);
	*(u32*)(xml_addr + (i * 4)) = xml_func_inst[i];
	}
	Hooks::xmlLoader_Stub = (Hooks::xmlLoader_t)DetourFunction((xml_addr), (void *)Hooks::xmlLoader_hook, 0x22);
	
	
	
    scePthreadExit(NULL);
    return NULL;
}
char msg_0[255];
char msg_1[255];
char buff_msg[255];
void *thread_func(void *arg) {
	int *p = (int *)arg;

	*p = *p + 1;

	return NULL;
}
unsigned int CRC32(const char* str) {
	size_t textLen = strlen(str);
	//int i = 0;
	unsigned int retHash = 0;
	//
	for (int i = 0; i < textLen; i++)
	{
		if (str[0] == '"')
		i = 1;
		char ctext = str[i];
		if (ctext == '"')
		break;
		if (ctext - 65 > 25)
		{
			if (ctext == '\\')
			ctext = '/';
		}
		else ctext += 32;
		retHash = (1032 * (retHash + ctext) >> 8) ^ 1032 * (retHash + ctext);
	}
	return 32769 * (9 * retHash ^ (10 * retHash >> 11));
}
extern "C" {
s32 attr_module_hidden module_start(size_t argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    final_printf("[GoldHEN] Plugin Author(s): %s\n", g_pluginAuth);
    boot_ver();
    struct proc_info procInfo;
    OrbisKernelModuleInfo CurrentModuleInfo;
    CurrentModuleInfo.size = sizeof(OrbisKernelModuleInfo);
    if(!get_module_info(CurrentModuleInfo, "0", &module_base, &module_size) && module_base && module_size)
    {
        final_printf("Could not find module info for current process\n");
        return -1;
    }
    if (sys_sdk_proc_info(&procInfo) == 0) {
    initImports();
    sprintf(msg_0, "Coded By @rfoodxmodz.");
    u32 crc32_hash = CRC32(msg_0);
    if(crc32_hash != 0xEB8BB9CB)
		goto end;
    sceSysUtilSendSystemNotificationWithText(222, "[GTAV] - ProjectV\nVersion: 1.2");
    sceSysUtilSendSystemNotificationWithText(222, msg_0);
     print_proc_info();
     OrbisPthread thread;
     scePthreadCreate(&thread, NULL, project_thread, NULL, "project_thread");
     scePthreadJoin(thread, NULL);
     end:
        return 0;
    }
    NotifyStatic(TEX_ICON_SYSTEM, "Unable to get process info from " STRINGIFY(sys_sdk_proc_info));
    return -1;
}
}

extern "C" {
s32 attr_module_hidden module_stop(s64 argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    return 0;
}
}
