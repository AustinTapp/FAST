/**
 * Examples/Filtering/gaussianSmoothingFilter.cpp
 *
 * If you edit this example, please also update the wiki and source code file in the repository.
 */
#include "ImageFileImporter.hpp"
#include "GaussianSmoothingFilter.hpp"
#include "ImageRenderer.hpp"
#include "SimpleWindow.hpp"

using namespace fast;

int main() {
    // Import image from file using the ImageFileImporter
    ImageFileImporter::pointer importer = ImageFileImporter::New();
    importer->setFilename(std::string(FAST_TEST_DATA_DIR)+"/US-2D.jpg");

    // Smooth image
    GaussianSmoothingFilter::pointer filter = GaussianSmoothingFilter::New();
    filter->setInput(importer->getOutput());
    filter->setStandardDeviation(2.0);
    filter->setMaskSize(7);

    // Renderer image
    ImageRenderer::pointer renderer = ImageRenderer::New();
    renderer->addInput(filter->getOutput());
    SimpleWindow::pointer window = SimpleWindow::New();
    window->addRenderer(renderer);
    window->setTimeout(5*1000); // automatically close window after 5 seconds
    window->start();
}
