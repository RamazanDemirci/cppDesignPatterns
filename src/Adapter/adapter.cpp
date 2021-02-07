#include <iostream>
#include <string>

enum VideoFormat
{
    H264,
    MJPEG,
    MPEG4
};

class Camera
{
public:
    virtual double getZoomValue() = 0;
    virtual void zoomIn() = 0;
    virtual void zoomOut() = 0;
    virtual void zoomDirect(double value) = 0;
    virtual VideoFormat getVideoFormat() = 0;
    virtual void setVideoFormat(VideoFormat format) = 0;
};

class IRCamera : public Camera
{
private:
    double m_zoomValue;
    const double m_zoomStepValue = 1.83f;
    const double m_zoomValueMIN = 2.2f;
    const double m_zoomValueMAX = 28.0f;
    VideoFormat m_videoFormat;

public:
    IRCamera()
    {
        m_zoomValue = 10.0f;
        m_videoFormat = VideoFormat::MJPEG;
    };

    virtual double getZoomValue() override
    {
        return m_zoomValue;
    };

    virtual void zoomIn() override
    {
        std::cout << "IRCamera::" << __FUNCTION__ << std::endl;
        m_zoomValue = (m_zoomValueMIN < (m_zoomValue - m_zoomStepValue)) ? m_zoomValue - m_zoomStepValue : m_zoomValueMIN;
        std::cout << "IRCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual void zoomOut() override
    {
        std::cout << "IRCamera::" << __FUNCTION__ << std::endl;
        m_zoomValue = (m_zoomValueMAX > (m_zoomValue + m_zoomStepValue)) ? m_zoomValue + m_zoomStepValue : m_zoomValueMAX;
        std::cout << "IRCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual void zoomDirect(double value) override
    {
        std::cout << "IRCamera::" << __FUNCTION__ << " value : " << value << std::endl;
        if (m_zoomValueMIN > value)
            m_zoomValue = m_zoomValueMIN;
        else if (m_zoomValueMAX < value)
            m_zoomValue = m_zoomValueMAX;
        else
            m_zoomValue = value;

        std::cout << "IRCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual VideoFormat getVideoFormat() override
    {
        std::cout << "IRCamera::" << __FUNCTION__ << std::endl;
        return m_videoFormat;
    };

    virtual void setVideoFormat(VideoFormat format) override
    {
        std::cout << "IRCamera::" << __FUNCTION__ << std::endl;
        m_videoFormat = format;
    };
};

class DayCamera : public Camera
{
private:
    double m_zoomValue;
    const double m_zoomStepValue = 1.56f;
    const double m_zoomValueMIN = 1.6f;
    const double m_zoomValueMAX = 52.0f;
    VideoFormat m_videoFormat;

public:
    DayCamera()
    {
        m_zoomValue = 8.0f;
        m_videoFormat = VideoFormat::MJPEG;
    };

    virtual double getZoomValue() override
    {
        return m_zoomValue;
    };

    virtual void zoomIn() override
    {
        std::cout << "DayCamera::" << __FUNCTION__ << std::endl;
        m_zoomValue = (m_zoomValueMIN < (m_zoomValue - m_zoomStepValue)) ? m_zoomValue - m_zoomStepValue : m_zoomValueMIN;
        std::cout << "DayCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual void zoomOut() override
    {
        std::cout << "DayCamera::" << __FUNCTION__ << std::endl;
        m_zoomValue = (m_zoomValueMAX > (m_zoomValue + m_zoomStepValue)) ? m_zoomValue + m_zoomStepValue : m_zoomValueMAX;
        std::cout << "DayCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual void zoomDirect(double value) override
    {
        std::cout << "DayCamera::" << __FUNCTION__ << " value : " << value << std::endl;
        if (m_zoomValueMIN > value)
            m_zoomValue = m_zoomValueMIN;
        else if (m_zoomValueMAX < value)
            m_zoomValue = m_zoomValueMAX;
        else
            m_zoomValue = value;

        std::cout << "DayCamera::Zoom Degree : " << m_zoomValue << std::endl;
    };

    virtual VideoFormat getVideoFormat() override
    {
        std::cout << "DayCamera::" << __FUNCTION__ << std::endl;
        return m_videoFormat;
    };

    virtual void setVideoFormat(VideoFormat format) override
    {
        std::cout << "DayCamera::" << __FUNCTION__ << std::endl;
        m_videoFormat = format;
    };
};

class CameraAdapter
{
    Camera *m_camera;

public:
    CameraAdapter(Camera *camera)
    {
        m_camera = camera;
    }

    double getZoomDegree() { return m_camera->getZoomValue(); };
    void zoomIn() { m_camera->zoomIn(); };
    void zoomOut() { m_camera->zoomOut(); };
    void setZoomDegree(double value) { m_camera->zoomDirect(value); };
    VideoFormat getVideoComressionFormat() { m_camera->getVideoFormat(); };
    void setVideoCompressionFormat(VideoFormat format) { m_camera->setVideoFormat(format); };
};

int main()
{
    Camera *cam = new IRCamera();
    CameraAdapter *camAdapter = new CameraAdapter(cam);

    camAdapter->setZoomDegree(18.58);
    std::cout << "Zoom Degree : " << camAdapter->getZoomDegree() << std::endl;
    camAdapter->setVideoCompressionFormat(VideoFormat::H264);
    camAdapter->zoomIn();
    camAdapter->zoomIn();
    camAdapter->zoomIn();
    std::cout << "Zoom Degree : " << camAdapter->getZoomDegree() << std::endl;
    camAdapter->zoomOut();
    camAdapter->zoomIn();
    camAdapter->zoomOut();
    std::cout << "Zoom Degree : " << camAdapter->getZoomDegree() << std::endl;
    camAdapter->setZoomDegree(8.99);
    std::cout << "Zoom Degree : " << camAdapter->getZoomDegree() << std::endl;

    return 0;
}


/*
Benefits of Adapter Design Pattern
 Open-Closed Principle: One advantage of the Adapter Pattern is that you don't need to change the existing class or interface. By introducing a new class, which acts as an adapter between the interface and the class, you avoid any changes to the existing code.
 This also limits the scope of your changes to your software component and avoids any changes and side-effects in other components or applications.
 By above two-point i.e. separate class(i.e. Single Responsibility Principle) for special functionality & fewer side-effects, it's obvious we do requires less maintenance, learning curve & testing.
 AdapterDesing Pattern also adheres to the Dependency Inversion Principle, due to which you can preserve binary compatibility between multiple releases.

When to use the Adapter Design Pattern?

-- Use the Adapter class when you want to use some existing class, but its interface isn't compatible with the rest of your code.
-- When you want to reuse several existing subclasses that lack some common functionality that can't be added to the superclass.

What are the differences between Bridge & Adapter Design Pattern?

-- Adapter is commonly used with an existing app to make some otherwise-incompatible classes work together nicely.
-- Bridge is usually designed up-front, letting you develop parts of an application independently of each other.

What is the difference between Decorator & Adapter Design Pattern?

-- Adapter converts one interface to another, without adding additional functionalities\
-- Decorator adds new functionality into an existing interface.


What is the difference between Proxy & Adapter Design Pattern?

-- Adapter Design Pattern translates the interface for one class into a compatible but different interface.
-- Proxy provides the same but easy interface or some time act as the only wrapper.
*/