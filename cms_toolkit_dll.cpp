/**
* @file   cms_toolkit_dll.cpp
* @brief  CMS Cross-platform C++ utility toolkit dll source
 * @author HeZhijun4030
 * @date   2026-05-28
 */
#include "cms_toolkit_dll.hpp"


namespace cms
{


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
