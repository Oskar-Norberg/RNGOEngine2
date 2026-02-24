//
// Created by ringo on 2026-02-21.
//

#include "Editor.h"

#include <iostream>

namespace rngo_editor
{
    Editor::Editor(const rngo::ApplicationConfig& config)
        : Application(config)
    {
    }

    void Editor::OnUpdate(const float deltaTime)
    {
        Application::OnUpdate(deltaTime);

        const auto importResult = m_assetLoader->ImportAsset("Assets/Grass.png");
        if (importResult)
        {
            std::cout << "Successfully imported: " << importResult->UUID.GetValue() << " "
                      << std::to_underlying(importResult->Type) << std::endl;

            m_assetLoader->RequestLoad(importResult.value());
            const auto assetOpt = m_assetRegistry->GetConsumed(importResult.value());

            if (assetOpt)
            {
                std::cout << "Found Asset: " << std::to_underlying(assetOpt.value()->GetType()) << std::endl;
            }
        }
        else
        {
            switch (importResult.error())
            {
                case rngo::AssetImportErrorCode::AssetNotFound:
                    std::cerr << "Failed to find asset!" << std::endl;
                    break;
                case rngo::AssetImportErrorCode::AssetNotSupported:
                    std::cerr << "Asset Type not supported!" << std::endl;
                    break;
                default:
                    break;
            }
        }
    }
}