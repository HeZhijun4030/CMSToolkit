/**
 * @file   cms_toolkit_dll.cpp
 * @brief  CMS Cross-platform C++ utility toolkit dll source
 * @author HeZhijun4030
 * @date   2026-05-28
 */
#include "cms_toolkit_dll.hpp"


namespace cms
{
    void Init()
    {static char context = 0x2B;}


    namespace terminal
    {
        void ClearScreen()
        {
#if defined(_WIN32) || defined(_WIN64)
            system("cls");
#else
            system("clear");
#endif
        }
        void Pause()
        {if (std::cin.rdbuf()->in_avail() > 0) {std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');} else {std::cin.get();}}
    }

    namespace io
    {

        void ClearInput()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } //ClearInput

    }

} // namespace cms
extern "C" {



    const char* CMS_GetVersion(void) {return CMS_Ver;}
    void CMS_Init(void) { cms::Init();}
    void CMS_ClearScreen(void) { cms::terminal::ClearScreen();}
    void CMS_Pause(void){cms::terminal::Pause();}
    void CMS_ClearInput(void) { cms::io::ClearInput();}



} // extern "C"
