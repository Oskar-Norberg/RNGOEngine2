//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <filesystem>
#include <memory>

#include "Asset/AssetDatabase/AssetDatabase.h"
#include "Asset/AssetFetcher/AssetFetcher.h"
#include "Asset/AssetLoader/AssetLoader.h"
#include "Asset/AssetRegistry/AssetRegistry.h"
#include "Events/EventQueue.h"
#include "Rendering/RenderRunnable.h"
#include "Rendering/Window/IWindow.h"

namespace rngo
{
    struct ApplicationConfig
    {
        std::string_view Title;

        int Width = 1280;
        int Height = 720;

        bool VSync = true;

        std::filesystem::path ProjectPath;
    };

    class Application
    {
    public:
        explicit Application(const ApplicationConfig& config);
        virtual ~Application();

        void Run();

    protected:
        EventQueue m_eventQueue;

    protected:
        // TODO: Note to self, combine all of the AssetFetcher, AssetDB, AssetRegistry under one AssetManager facade
        std::unique_ptr<AssetDatabase> m_assetDatabase;
        std::unique_ptr<AssetFetcher> m_assetFetcher;
        std::unique_ptr<AssetRegistry> m_assetRegistry;
        std::unique_ptr<AssetLoader> m_assetLoader;

    protected:
        std::unique_ptr<IWindow> m_window;
        std::unique_ptr<RenderRunnable> m_renderRunnable;

    protected:
        virtual void OnUpdate(float deltaTime)
        {
        }
    };
}