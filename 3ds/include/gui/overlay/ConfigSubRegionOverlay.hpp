/*
 *   This file is part of PKSM
 *   Copyright (C) 2016-2020 Bernardo Giordano, Admiral Fish, piepie62
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef CONFIGSUBREGIONOVERLAY_HPP
#define CONFIGSUBREGIONOVERLAY_HPP

#include "Hid.hpp"
#include "ReplaceableScreen.hpp"
#include <map>
#include <memory>

class Button;

class ConfigSubRegionOverlay : public ReplaceableScreen
{
public:
    ConfigSubRegionOverlay(ReplaceableScreen& screen);
    void drawTop() const override;
    bool replacesTop() const override { return true; }
    void drawBottom() const override;
    void update(touchPosition* touch) override;

private:
    void searchBar();
    Hid<HidDirection::VERTICAL, HidDirection::HORIZONTAL> hid;
    const std::map<u8, std::string>& validSubRegions;
    std::map<u8, std::string> subregions;
    std::string searchString    = "";
    std::string oldSearchString = "";
    std::unique_ptr<Button> searchButton;
    bool justSwitched = true;
};

#endif
