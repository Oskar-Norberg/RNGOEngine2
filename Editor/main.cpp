//
// Created by ringo on 2026-02-21.
//

#include <memory>

#include "Entrypoint.h"
#include "Application.h"
#include "Editor.h"

namespace rngo
{
    std::unique_ptr<Application> CreateApplication()
    {
        return std::make_unique<rngo_editor::Editor>();
    }
}

int main(int argc, char** argv)
{
    return rngo::Main(argc, argv);
}