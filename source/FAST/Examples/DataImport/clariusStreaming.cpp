/**
 * @example clariusStreaming.cpp
 */
#include <FAST/Streamers/ClariusStreamer.hpp>
#include <FAST/Visualization/SimpleWindow.hpp>
#include <FAST/Visualization/ImageRenderer/ImageRenderer.hpp>

using namespace fast;

int main() {
    Config::setStreamingMode(STREAMING_MODE_NEWEST_FRAME_ONLY);
    auto streamer = ClariusStreamer::create();

    auto renderer = ImageRenderer::create()
            ->connect(streamer);

    auto window = SimpleWindow2D::create()
            ->connect(renderer);
    window->getView()->setAutoUpdateCamera(true);
    window->run();
}