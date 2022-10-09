#include "stdafx.h"
#include "export.h"

#if !(ENABLE_STATIC_COMPILATION)
__shared_api_ void* __stdcall api_object_init(const void*, unsigned long) {
 void* result = nullptr;
 do {

 } while (0);
 return result;
}

__shared_api_ void __stdcall api_object_uninit() {

}
#endif///#if !(ENABLE_STATIC_COMPILATION)
