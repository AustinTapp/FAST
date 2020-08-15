#include "SimpleWindow.hpp"
#include <QHBoxLayout>

namespace fast {

void SimpleWindow::addRenderer(std::shared_ptr<Renderer> renderer) {
    getViews()[0]->addRenderer(renderer);
}

void SimpleWindow::removeAllRenderers() {
    getViews()[0]->removeAllRenderers();
}

void SimpleWindow::setMaximumFramerate(unsigned int framerate) {
    getViews()[0]->setMaximumFramerate(framerate);
}

SimpleWindow::~SimpleWindow() {
}

SimpleWindow::SimpleWindow() {
    View* view = createView();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mWidget->setLayout(mainLayout);
    mWidget->setContentsMargins(0, 0, 0, 0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
}

void SimpleWindow::set2DMode() {
    getView()->set2DMode();
}

void SimpleWindow::set3DMode() {
    getView()->set3DMode();
}

View* SimpleWindow::getView() const {
    return Window::getView(0);
}

} // end namespace fast
