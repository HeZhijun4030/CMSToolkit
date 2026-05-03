/**
* @file   cms_toolkit_dll.cpp
* @brief  CMS Cross-platform C++ utility toolkit dll source
 * @author HeZhijun4030
 * @date   2026-05-03
 */
#include "cms_toolkit_dll.hpp"


namespace cms
{
    namespace tween
    {

        /*
         * TODO(Hzj) hey check out this
补间动画核心计算公式
一、基础公式
给定：
开始值：start
结束值：end
持续时间：duration（毫秒）
当前时间：currentTime
开始时间：startTime
二、核心计算步骤
1. 计算原始进度
progress = (currentTime - startTime) / duration
progress = clamp(progress, 0, 1)  // 限制在 0~1 之间
2. 应用缓动曲线
easedProgress = easing(progress)  // 0~1 之间的值
3. 计算当前值
currentValue = start + (end - start) * easedProgress
三、常用缓动曲线公式
类型	公式 easing(t)	效果
线性	t	匀速
二次加速	t²	慢→快
二次减速	1 - (1-t)²	快→慢
三次加速	t³	更明显的慢→快
三次减速	1 - (1-t)³	更明显的快→慢
四次加速	t⁴	极慢→极快
四次减速	1 - (1-t)⁴	极快→极慢
正弦加速	1 - cos(t * π/2)	平滑启动
正弦减速	sin(t * π/2)	平滑停止
弹性出	1 - 2^(-10*t) * sin((t-0.075) * 2π/0.3)	弹跳效果
回退出	1 + 2.70158*(t-1)³ + 1.70158*(t-1)²	超过目标再回来
*/
        BaseTween::BaseTween(const float& st, const float& fi, const float& du, const Curve& cu) :
            StartValue(st),
            FinalValue(fi),
            Duration(du),
            CurCurve(cu),
            IsRunning(false),
            StartTime(static_cast<float>(0)),
            BindTarget(nullptr),
            Finished(false)
        {}

        void BaseTween::Start(){StartTime=GetCurrentTimeMs();IsRunning=true;}

        float BaseTween::Update()
        {
            if (!GetIsRunning()) return FinalValue;
            const auto now = GetCurrentTimeMs();
            //                      elapsed
            const float progress = (now - StartTime)  / Duration;
            if (progress >= 1.0f) {IsRunning = false;return FinalValue;}
            return StartValue + (FinalValue-StartValue) * ApplyCurve(progress);
        }

        void BaseTween::BindToTarget(float& Target){BindTarget = &Target;}

        void BaseTween::ApplyToUpdate()
        {
            if (!GetIsRunning()) BindTarget=nullptr;
            const auto now = GetCurrentTimeMs();
            //         你说得对这是  (elapsed VALUE)  /   持续 = 进度
            const float progress = (now - StartTime)  / Duration;
            if (progress >= 1.0f) {IsRunning = false;if (BindTarget) *BindTarget=FinalValue;BindTarget=nullptr;}
            if (BindTarget) *BindTarget = StartValue + (FinalValue-StartValue) * ApplyCurve(progress);
        }

        bool BaseTween::GetIsRunning() const{return IsRunning;}

        float BaseTween::GetCurrentTimeMs() {return
            std::chrono::duration<float, std::milli>(
                std::chrono::steady_clock::now()
                .time_since_epoch())
            .count();
        }


        float BaseTween::ApplyCurve(const float& t)const{switch (CurCurve){case Curve::Linear:return t;case Curve::QuadIn:return t*t;default: return t;}}
    }


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
