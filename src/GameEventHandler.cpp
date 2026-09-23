#include "GameEventHandler.h"
#include "Hooks.h"

namespace plugin {
    void GameEventHandler::onLoad() {
        logger::info("onLoad()");
        Hooks::install();
    }

    void GameEventHandler::onPostLoad() {
        logger::info("onPostLoad()");
    }

    void GameEventHandler::onPostPostLoad() {
        logger::info("onPostPostLoad()");
    }

    void GameEventHandler::onInputLoaded() {
        logger::info("onInputLoaded()");
    }

    void GameEventHandler::onDataLoaded() {
        auto crosshair_addr = REL::RelocationID(39534, 40620).address();
        if (crosshair_addr) {
            auto crosshair_patch_addr=crosshair_addr + REL::VariantOffset(0x60, 0x65, 0x60).offset();
            REL::safe_write(crosshair_patch_addr, "\x90\x90\x90\x90\x90\x90",6);
            logger::info("CrosshairRefEvents Fixed");
        }
        logger::info("onDataLoaded()");
    }

    void GameEventHandler::onNewGame() {
        logger::info("onNewGame()");
    }

    void GameEventHandler::onPreLoadGame() {
        logger::info("onPreLoadGame()");
    }

    void GameEventHandler::onPostLoadGame() {
        logger::info("onPostLoadGame()");
    }

    void GameEventHandler::onSaveGame() {
        logger::info("onSaveGame()");
    }

    void GameEventHandler::onDeleteGame() {
        logger::info("onDeleteGame()");
    }
}  // namespace plugin