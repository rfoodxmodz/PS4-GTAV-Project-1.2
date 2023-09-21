#include "utility.h"
#include "imports.h"
#include "vars.h"


void Sleep(unsigned int milliseconds) {
	sceKernelUsleep(milliseconds * 1000);
}

void WriteJump(uint64_t address, uint64_t destination) {
	sceKernelMprotect((void*)address, 14, VM_PROT_ALL);
	*(uint8_t *)(address) = 0xFF;
	*(uint8_t *)(address + 1) = 0x25;
	*(uint8_t *)(address + 2) = 0x00;
	*(uint8_t *)(address + 3) = 0x00;
	*(uint8_t *)(address + 4) = 0x00;
	*(uint8_t *)(address + 5) = 0x00;
	*(uint64_t *)(address + 6) = destination;
}

void ReadMemory(uint64_t address, void *buffer, int length) {
	sceKernelMprotect(buffer, length, VM_PROT_ALL);
	memcpy(buffer, (void *)address, length);
}

void WriteMemory(uint64_t address, void *buffer, int length) {
	sceKernelMprotect((void*)address, length, VM_PROT_ALL);
	memcpy((void *)address, buffer, length);
}




/*
 * Convert a string to an unsigned long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
 int ISDIGIT (char c) {
    return (c>='0') && (c<='9');
}
int ISALPHA(int c)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz";
    char *letter = alphabet;

    while(*letter != '\0' && *letter != c)
        ++letter;

    if (*letter)
        return 1;

    return 0;
}
int ISUPPER(int ch)
{
return ((ch >= 'A' && ch <= 'Z')) || (ch >= 0xC0 && ch <= 0xDD);
}
int ISSPACE(int c)
{
  return ((c == ' ') || (c == '\n') || (c == '\t'));
}

constexpr u32 MAX_PATTERN_LENGTH = 256;
u32 pattern_to_byte(const char* pattern, uint8_t* bytes)
{
    u32 count = 0;
    const char* start = pattern;
    const char* end = pattern + strlen(pattern);

    for (const char* current = start; current < end; ++current)
    {
        if (*current == '?')
        {
            ++current;
            if (*current == '?')
            {
                ++current;
            }
            bytes[count++] = -1;
        }
        else
        {
            bytes[count++] = strtoul(current, (char**)&current, 16);
        }
    }
    return count;
}
/*
 * @brief Scan for a given byte pattern on a module
 *
 * @param module_base Base of the module to search
 * @param module_size Size of the module to search
 * @param signature   IDA-style byte array pattern
 * @credit            https://github.com/OneshotGH/CSGOSimple-master/blob/59c1f2ec655b2fcd20a45881f66bbbc9cd0e562e/CSGOSimple/helpers/utils.cpp#L182
 * @returns           Address of the first occurrence
 */
u8* PatternScan(uint64_t module_base, uint32_t module_size, const char* signature)
{
    if (!module_base || !module_size)
    {
        return nullptr;
    }
    u8 patternBytes[MAX_PATTERN_LENGTH];
    s32 patternLength = pattern_to_byte(signature, patternBytes);
    if (!patternLength || patternLength >= MAX_PATTERN_LENGTH)
    {
       // final_printf("Pattern length too large or invalid! %i (0x%08x)\n", patternLength, patternLength);
       // final_printf("Input Pattern %s\n", signature);
        return nullptr;
    }
    u8* scanBytes = (uint8_t*)module_base;

    for (u64 i = 0; i < module_size; ++i)
    {
        bool found = true;
        for (s32 j = 0; j < patternLength; ++j)
        {
            if (scanBytes[i + j] != patternBytes[j] && patternBytes[j] != 0xff)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return &scanBytes[i];
        }
    }
    return nullptr;
}
int toLowerx(int chr)//touches only one character per call
{
    return (chr >='A' && chr<='Z') ? (chr + 32) : (chr);    
}
char * StrToLower(char *str)
{
    char *pNew1 = str;
    char *pNew2 = str;

    if(str != NULL) //NULL ?
    {
        if(strlen(str) != 0) //"" ?
        {
            while(*pNew1)
            {
                *pNew2 = toLowerx(*pNew1); 
                ++pNew2;
                ++pNew1;
            }
            *pNew2 = '\0';
            return str;// return changed string
        }              // and prevent returning null to caller
    }
    return "";//Will never get here for non-null input argurment
}   


int our_tolower ( int c)
{

    

if (c >= 'A' && c <= 'Z' )

        

return (c + 32);

    

return (c);

}

char* toLower(char* s) {
char* p;
  for(p=s; *p; p++) *p=our_tolower(*p);
  return s;
}
bool file_exists (char *filename) {
  struct stat   buffer;   
  return (sceKernelStat (filename, &buffer) == 0);
}
char v_gBuffer3[255];
char v_gBuffer4[255];
bool gfx_exists_ (const char* path, const char *filename) {
	if(strstr(path, filename) && strstr(filename, ".")) {
		sprintf(v_gBuffer3, "/data/gta5/gfx/%s", filename);
		//sceKernelChmod(v_gBuffer, 0777);
		return file_exists(v_gBuffer3);
	}
	return 0;
}
char txt[255];
char* file_exists_ (const char *data_path,   char* a2) {
//commoncrc:/data/ai/weaponcomponents.meta

	sprintf(v_gBuffer4, "%s", data_path);
	if( file_exists(v_gBuffer4)) return v_gBuffer4;
	sprintf(v_gBuffer4, "%s", a2);
	if(strstr(v_gBuffer4, "weaponcomponents.meta")) {
	sprintf(txt, "File Not Exist: %s", v_gBuffer4);
	//sceSysUtilSendSystemNotificationWithText(222, txt);
	
	}
	return v_gBuffer4;
}


char* toLoweRiii(char* strr) {
//memset(tolowerBufferr, 0, sizeof(tolowerBufferr));
sprintf(tolowerBufferrr, "%s", strr);
for(int i=0;i<strlen(strr);i++) {
for(int j=0;j<strlen(charsettt);j++) {
if(strr[i] == charsettt[j]) tolowerBufferrr[i] = charsettt_l[j];
}
}
return tolowerBufferrr;
}
char pbuf[255];
char* pprintf(const char *format, ...) {
  va_list arglist;
  va_start( arglist, format );
  vsprintf(pbuf,format,arglist);
  va_end( arglist );
  return pbuf;
}

char* unescape(const char *s) {
    s64 len = strlen(s);
    char *unescaped_str = (char *)malloc(len + 1);
    u32 i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        if (s[i] == '\\') {
            i++;
            switch (s[i]) {
                case 'n':
                    unescaped_str[j] = '\n';
                    break;
                case '0':
                    unescaped_str[j] = '\0';
                    break;
                case 't':
                    unescaped_str[j] = '\t';
                    break;
                case 'r':
                    unescaped_str[j] = '\r';
                    break;
                case '\\':
                    unescaped_str[j] = '\\';
                    break;
                case 'x':
                    {
                        char hex_string[3] = {0};
                        u32 val = 0;
                        hex_string[0] = s[++i];
                        hex_string[1] = s[++i];
                        hex_string[2] = '\0';
                        if (sscanf(hex_string, "%x", &val) != 1) {
                            final_printf("Invalid hex escape sequence: %s\n", hex_string);
                            val = '?';
                        }
                        unescaped_str[j] = (char)val;
                    }
                    break;
                default:
                    unescaped_str[j] = s[i];
                    break;
            }
        } else {
            unescaped_str[j] = s[i];
        }
    }
    unescaped_str[j] = '\0';
    return unescaped_str;
}

// valid hex look up table.
const u8 hex_lut[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00 };

u8 *hexstrtochar2(const char *hexstr, s64 *size) {

    u32 str_len = strlen(hexstr);
    s64 data_len = ((str_len + 1) / 2) * sizeof(u8);
    *size = (str_len) * sizeof(u8);
    u8 *data = (u8 *)malloc(*size);
    u32 j = 0; // hexstr position
    u32 i = 0; // data position

    if (str_len % 2 == 1) {
        data[i] = (u8)(hex_lut[0] << 4) | hex_lut[(u8)hexstr[j]];
        j = ++i;
    }

    for (; j < str_len; j += 2, i++) {
        data[i] = (u8)(hex_lut[(u8)hexstr[j]] << 4) |
                  hex_lut[(u8)hexstr[j + 1]];
    }

    *size = data_len;
    return data;
}

void sys_proc_rw(u64 Address, void *Data, u64 Length)
{
    if (!Address || !Length)
    {
        final_printf("No target (0x%lx) or length (%li) provided!\n", Address, Length);
        return;
    }
    sceKernelMprotect((void*)Address, Length, VM_PROT_ALL);
    memcpy((void*)Address, Data, Length);
}

void memcpy_p(u64 Address, const void *Data, u64 Length)
{
    if (!Address || !Length)
    {
        final_printf("No target (0x%lx) or length (%li) provided!\n", Address, Length);
        return;
    }
    sceKernelMprotect((void*)Address, Length, VM_PROT_ALL);
    memcpy((void*)Address, Data, Length);
}

bool hex_prefix(const char *str)
{
    return (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'));
}

// http://www.cse.yorku.ca/~oz/hash.html
constexpr u64 djb2_hash(const char *str) {
    u64 hash = 5381;
    u32 c = 0;
    while ((c = *str++))
        hash = hash * 33 ^ c;
    return hash;
}

u64 patch_hash_calc(const char *title, const char *name, const char *app_ver,
                    const char *title_id, const char *elf) {
    u64 output_hash = 0;
    char hash_str[256] = {0};
    snprintf(hash_str, sizeof(hash_str), "%s%s%s%s%s", title, name, app_ver,
             title_id, elf);
    output_hash = djb2_hash(hash_str);
    debug_printf("input: \"%s\"\n", hash_str);
    debug_printf("output: 0x%016lx\n", output_hash);
    return output_hash;
}

void patch_data1(const char* patch_type_str, u64 addr, const char *value, uint32_t source_size, uint64_t jump_target)
{
    u8 arr8[1] = {0};
    u8 arr16[2] = {0};
    u8 arr32[4] = {0};
    u8 arr64[8] = {0};
    u64 patch_type = djb2_hash(patch_type_str);
    switch(patch_type)
    {
        case djb2_hash("byte"):
        case djb2_hash("mask_byte"):
        {
            u8 real_value = 0;
            if (hex_prefix(value)) {
                real_value = strtol(value, NULL, 16);
            } else {
                real_value = strtol(value, NULL, 10);
            }
            memcpy(arr8, &real_value, sizeof(arr8));
            sys_proc_rw(addr, arr8, sizeof(arr8));
            break;
        }
        case djb2_hash("bytes16"):
        case djb2_hash("mask_bytes16"):
        {
            u16 real_value = 0;
            if (hex_prefix(value)) {
                real_value = strtol(value, NULL, 16);
            } else {
                real_value = strtol(value, NULL, 10);
            }
            memcpy(arr16, &real_value, sizeof(arr16));
            sys_proc_rw(addr, arr16, sizeof(arr16));
            break;
        }
        case djb2_hash("bytes32"):
        case djb2_hash("mask_bytes32"):
        {
            u32 real_value = 0;
            if (hex_prefix(value)) {
                real_value = strtol(value, NULL, 16);
            } else {
                real_value = strtol(value, NULL, 10);
            }
            memcpy(arr32, &real_value, sizeof(arr32));
            sys_proc_rw(addr, arr32, sizeof(arr32));
            break;
        }
        case djb2_hash("bytes64"):
        case djb2_hash("mask_bytes64"):
        {
            s64 real_value = 0;
            if (hex_prefix(value)) {
                real_value = strtoll(value, NULL, 16);
            } else {
                real_value = strtoll(value, NULL, 10);
            }
            memcpy(arr64, &real_value, sizeof(arr64));
            sys_proc_rw(addr, arr64, sizeof(arr64));
            break;
        }
        case djb2_hash("bytes"):
        case djb2_hash("mask"):
        case djb2_hash("mask_bytes"):
        {
            s64 bytearray_size = 0;
            u8 *bytearray = hexstrtochar2(value, &bytearray_size);
            sys_proc_rw(addr, bytearray, bytearray_size);
            free(bytearray);
            break;
        }
        case djb2_hash("float32"):
        case djb2_hash("mask_float32"):
        {
            f32 real_value = 0;
            real_value = strtod(value, NULL);
            memcpy(arr32, &real_value, sizeof(arr32));
            sys_proc_rw(addr, arr32, sizeof(arr32));
            break;
        }
        case djb2_hash("float64"):
        case djb2_hash("mask_float64"):
        {
            f64 real_value = 0;
            real_value = strtod(value, NULL);
            memcpy(arr64, &real_value, sizeof(arr64));
            sys_proc_rw(addr, arr64, sizeof(arr64));
            break;
        }
        case djb2_hash("utf8"):
        case djb2_hash("mask_utf8"):
        {
            char* new_str = unescape(value);
            u64 char_len = strlen(new_str);
            sys_proc_rw(addr, (void*)new_str, char_len + 1); // get null
            free(new_str);
            break;
        }
        case djb2_hash("utf16"):
        case djb2_hash("mask_utf16"):
        {
            char* new_str = unescape(value);
            for (u32 i = 0; new_str[i] != '\x00'; i++)
            {
                u8 val_ = new_str[i];
                u8 value_[2] = {val_, 0x00};
                sys_proc_rw(addr, value_, sizeof(value_));
                addr = addr + 2;
            }
            u8 value_[2] = {0x00, 0x00};
            sys_proc_rw(addr, value_, sizeof(value_));
            free(new_str);
            break;
        }
        case djb2_hash("mask_jump32"):
        {
            if (source_size < 5)
            {
                final_printf("Can't create code cave with size less than 32 bit jump!\n");
                break;
            }
            s64 bytearray_size = 0;
            u8 *bytearray = hexstrtochar2(value, &bytearray_size);
            u64 code_cave_end = jump_target + bytearray_size;
            for (u32 i = 0; i < source_size; i++)
            {
                u8 nop_byte[] = { 0x90 };
                sys_proc_rw(addr + i, nop_byte, sizeof(nop_byte));
            }
            u8 jump_32[] = { 0xe9, 0x00, 0x00, 0x00, 0x00 };
            s32 target_jmp = (s32) (jump_target - addr - sizeof(jump_32));
            s32 target_return = (s32) (addr) - (code_cave_end);
            sys_proc_rw(jump_target, bytearray, bytearray_size);
            sys_proc_rw(addr, jump_32, sizeof(jump_32));
            memcpy(arr32, &target_jmp, sizeof(target_jmp));
            sys_proc_rw(addr + 1, arr32, sizeof(arr32));
            sys_proc_rw(jump_target + bytearray_size, jump_32, sizeof(jump_32));
            memcpy(arr32, &target_return, sizeof(target_return));
            sys_proc_rw(code_cave_end + 1, arr32, sizeof(arr32));
            free(bytearray);
            break;
        }
        default:
        {
            final_printf("Patch type: '%s (#%.16lx) not found or unsupported\n", patch_type_str, patch_type);
            final_printf("Patch data:\n");
            final_printf("      Address: 0x%lx\n", addr);
            final_printf("      Value: %s\n", value);
            final_printf("      Jump Size: %u\n", source_size);
            final_printf("      Jump Target: 0x%lx\n", jump_target);
            break;
        }
    }
}
