#pragma once
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
std::string base64_encode(unsigned char const*, unsigned int len);
std::vector<std::string> aplr(std::string path, std::wstring countryCode);
#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */

