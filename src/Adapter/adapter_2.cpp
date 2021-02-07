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

enum VideoCompression
{
    IR_H264,
    IR_MJPEG,
    IR_MPEG4
};

class OldIRCamera
{
private:
    double m_zoomDegree;
    const double m_zoomStepValue = 1.56f;
    const double m_zoomValueMIN = 1.6f;
    const double m_zoomValueMAX = 52.0f;
    VideoCompression m_videoFormat;

public:
    OldIRCamera()
    {
        m_zoomDegree = 8.0f;
        m_videoFormat = VideoCompression::IR_MJPEG;
    };

    double getZoomDegree()
    {
        return m_zoomDegree;
    };

    void applyZoomIn()
    {
        std::cout << "OldIRCamera::" << __FUNCTION__ << std::endl;
        m_zoomDegree = (m_zoomValueMIN < (m_zoomDegree - m_zoomStepValue)) ? m_zoomDegree - m_zoomStepValue : m_zoomValueMIN;
        std::cout << "OldIRCamera::Zoom Degree : " << m_zoomDegree << std::endl;
    };

    void applyZoomOut()
    {
        std::cout << "OldIRCamera::" << __FUNCTION__ << std::endl;
        m_zoomDegree = (m_zoomValueMAX > (m_zoomDegree + m_zoomStepValue)) ? m_zoomDegree + m_zoomStepValue : m_zoomValueMAX;
        std::cout << "OldIRCamera::Zoom Degree : " << m_zoomDegree << std::endl;
    };

    void setZoom(double value)
    {
        std::cout << "OldIRCamera::" << __FUNCTION__ << " value : " << value << std::endl;
        if (m_zoomValueMIN > value)
            m_zoomDegree = m_zoomValueMIN;
        else if (m_zoomValueMAX < value)
            m_zoomDegree = m_zoomValueMAX;
        else
            m_zoomDegree = value;

        std::cout << "OldIRCamera::Zoom Degree : " << m_zoomDegree << std::endl;
    };

    VideoCompression getVideoCompression()
    {
        std::cout << "OldIRCamera::" << __FUNCTION__ << std::endl;
        return m_videoFormat;
    };

    void setVideoCompression(VideoCompression format)
    {
        std::cout << "OldIRCamera::" << __FUNCTION__ << std::endl;
        m_videoFormat = format;
    };
};

class OldIRCameraAdapter : public Camera, private OldIRCamera
{
public:
    virtual double getZoomValue() override { getZoomDegree(); };
    virtual void zoomIn() override { applyZoomIn(); };
    virtual void zoomOut() override { applyZoomOut(); };
    virtual void zoomDirect(double value) override { setZoom(value); };
    virtual VideoFormat getVideoFormat() override { getVideoCompression(); };
    virtual void setVideoFormat(VideoFormat format) override
    {
        switch (format)
        {
        case VideoFormat::H264:
            setVideoCompression(VideoCompression::IR_H264);
        case VideoFormat::MJPEG:
            setVideoCompression(VideoCompression::IR_MJPEG);
        case VideoFormat::MPEG4:
            setVideoCompression(VideoCompression::IR_MPEG4);
        default:
            std::cout << "Unsupported Video Format" << std::endl;
        }
    };
};

int main()
{

    Camera *cam;
    std::cout << "[0]IRCamera, [1]OldIRCamera" << std::endl;

    int choice;
    std::cin >> choice;
    if (choice == 0)
        cam = new IRCamera();
    else
        cam = new OldIRCameraAdapter();

    cam->zoomDirect(18.58);
    std::cout << "Zoom Degree : " << cam->getZoomValue() << std::endl;
    cam->setVideoFormat(VideoFormat::H264);
    cam->zoomIn();
    cam->zoomIn();
    cam->zoomIn();
    std::cout << "Zoom Degree : " << cam->getZoomValue() << std::endl;
    cam->zoomOut();
    cam->zoomIn();
    cam->zoomOut();
    std::cout << "Zoom Degree : " << cam->getZoomValue() << std::endl;
    cam->zoomDirect(8.99);
    std::cout << "Zoom Degree : " << cam->getZoomValue() << std::endl;

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