//
// Created by ringo on 2026-02-21.
//

#include <memory>

#include "Application.h"
#include "Editor.h"
#include "Entrypoint.h"

namespace rngo
{
    std::unique_ptr<Application> CreateApplication()
    {
        ApplicationConfig config{
            .Title = "RNGOEditor",
            .Width = 1280,
            .Height = 720,
            .VSync = false,
            // NOTE: Temporary path, should be set on launching Editor
            .ProjectPath = std::filesystem::current_path() / "EditorProject"
        };

        return std::make_unique<rngo_editor::Editor>(config);
    }
}

int main(int argc, char** argv)
{
    return rngo::Main(argc, argv);
}