#include "DualViewWindow.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace fast {

void DualViewWindow::addRendererToTopLeftView(
        Renderer::pointer renderer) {
    getView(0)->addRenderer(renderer);
}

void DualViewWindow::addRendererToBottomRightView(
        Renderer::pointer renderer) {
    getView(1)->addRenderer(renderer);
}

void DualViewWindow::removeAllRenderers() {
    getView(0)->removeAllRenderers();
    getView(1)->removeAllRenderers();
}

View* DualViewWindow::getTopLeftView() {
    return getView(0);
}

View* DualViewWindow::getBottomRightView() {
    return getView(1);
}

void DualViewWindow::setHorizontalMode() {
    mVerticalMode = false;
    createLayout();
}

void DualViewWindow::setVerticalMode() {
    mVerticalMode = true;
    createLayout();
}

DualViewWindow::~DualViewWindow() {
}

DualViewWindow::DualViewWindow(Color bgcolor, int width, int height, bool verticalMode) {
    View* view1 = createView();
    View* view2 = createView();

    createLayout();
    if(verticalMode) {
        setVerticalMode();
    } else {
        setHorizontalMode();
    }
    if(width > 0)
        setWidth(width);
    if(height > 0)
        setHeight(height);
    view1->setBackgroundColor(bgcolor);
    view2->setBackgroundColor(bgcolor);
}

void DualViewWindow::createLayout() {
    // Add new layout
    if(mVerticalMode) {
        auto mainLayout = new QVBoxLayout;
        mainLayout->addWidget(getView(0));
        mainLayout->addWidget(getView(1));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        setCenterLayout(mainLayout);
    } else {
        auto mainLayout = new QHBoxLayout;
        mainLayout->addWidget(getView(0));
        mainLayout->addWidget(getView(1));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        setCenterLayout(mainLayout);
    }
}

void DualViewWindow::addRendererToLeftView(Renderer::pointer renderer) {
    addRendererToTopLeftView(renderer);
}

void DualViewWindow::addRendererToRightView(Renderer::pointer renderer) {
    addRendererToBottomRightView(renderer);
}

void DualViewWindow::addRendererToTopView(Renderer::pointer renderer) {
    addRendererToTopLeftView(renderer);
}

void DualViewWindow::addRendererToBottomView(Renderer::pointer renderer) {
    addRendererToBottomRightView(renderer);
}

void DualViewWindow::setBackgroundColor(Color color) {
    getView(0)->setBackgroundColor(color);
    getView(1)->setBackgroundColor(color);
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectLeft(std::shared_ptr<Renderer> renderer) {
    addRendererToLeftView(renderer);
    return std::dynamic_pointer_cast<DualViewWindow>(mPtr.lock());
}
std::shared_ptr<DualViewWindow> DualViewWindow::connectLeft(std::vector<std::shared_ptr<Renderer>> renderers) {
    for(auto renderer : renderers)
        addRendererToLeftView(renderer);
    return std::dynamic_pointer_cast<DualViewWindow>(mPtr.lock());
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectTop(std::shared_ptr<Renderer> renderer) {
    return connectLeft(renderer);
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectTop(std::vector<std::shared_ptr<Renderer>> renderers) {
    return connectLeft(renderers);
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectRight(std::shared_ptr<Renderer> renderer) {
    addRendererToRightView(renderer);
    return std::dynamic_pointer_cast<DualViewWindow>(mPtr.lock());
}
std::shared_ptr<DualViewWindow> DualViewWindow::connectRight(std::vector<std::shared_ptr<Renderer>> renderers) {
    for(auto renderer : renderers)
        addRendererToRightView(renderer);
    return std::dynamic_pointer_cast<DualViewWindow>(mPtr.lock());
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectBottom(std::shared_ptr<Renderer> renderer) {
    return connectRight(renderer);
}

std::shared_ptr<DualViewWindow> DualViewWindow::connectBottom(std::vector<std::shared_ptr<Renderer>> renderers) {
    return connectRight(renderers);
}

void DualViewWindow::addWidget(QWidget *widget) {
    Window::connect(widget);
}

std::shared_ptr<DualViewWindow> DualViewWindow::connect(QWidget *widget) {
    addWidget(widget);
    return std::dynamic_pointer_cast<DualViewWindow>(mPtr.lock());
}

std::shared_ptr<Window> DualViewWindow::connect(uint id, std::shared_ptr<DataObject> data) {
    throw Exception("DualView window expects a renderer");
    return Window::connect(id, data);
}

std::shared_ptr<Window> DualViewWindow::connect(uint id, std::shared_ptr<ProcessObject> PO, uint portID) {
    return Window::connect(id, PO, portID);
}

DualViewWindow2D::DualViewWindow2D(Color bgcolor, int width, int height, bool verticalMode) : DualViewWindow(bgcolor, width, height, verticalMode) {
    set2DMode();
}

DualViewWindow3D::DualViewWindow3D(Color bgcolor, int width, int height, bool verticalMode) : DualViewWindow(bgcolor, width, height, verticalMode) {
    set3DMode();
}

} // end namespace fast
