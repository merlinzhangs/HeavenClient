//////////////////////////////////////////////////////////////////////////////////
//	This file is part of the continued Journey MMORPG client					//
//	Copyright (C) 2015-2019  Daniel Allendorf, Ryan Payton						//
//																				//
//	This program is free software: you can redistribute it and/or modify		//
//	it under the terms of the GNU Affero General Public License as published by	//
//	the Free Software Foundation, either version 3 of the License, or			//
//	(at your option) any later version.											//
//																				//
//	This program is distributed in the hope that it will be useful,				//
//	but WITHOUT ANY WARRANTY; without even the implied warranty of				//
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				//
//	GNU Affero General Public License for more details.							//
//																				//
//	You should have received a copy of the GNU Affero General Public License	//
//	along with this program.  If not, see <https://www.gnu.org/licenses/>.		//
//////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../UIElement.h"

#include "../Graphics/Text.h"

namespace ms
{
	class UINpcTalk : public UIElement
	{
	public:
		enum TalkType : int8_t
		{
			NONE = -1,
			SENDOK,
			SENDYESNO,

			// TODO: Unconfirmed
			SENDNEXT,
			SENDNEXTPREV,
			SENDACCEPTDECLINE,
			SENDGETTEXT,
			SENDGETNUMBER,
			SENDSIMPLE,
			LENGTH
		};

		static constexpr Type TYPE = UIElement::Type::NPCTALK;
		static constexpr bool FOCUSED = true;
		static constexpr bool TOGGLED = false;

		UINpcTalk();

		void draw(float inter) const override;

		void send_key(int32_t keycode, bool pressed, bool escape) override;

		void change_text(int32_t npcid, int8_t msgtype, int16_t style, int8_t speaker, const std::string& text);

	protected:
		Button::State button_pressed(uint16_t buttonid) override;

	private:
		TalkType get_by_value(int8_t value);
		std::string format_text(const std::string& tx, const int32_t& npcid);

		enum Buttons
		{
			ALLLEVEL,
			CLOSE,
			MYLEVEL,
			NEXT,
			NO,
			OK,
			PREV,
			QAFTER,
			QCNO,
			QCYES,
			QGIVEUP,
			QNO,
			QSTART,
			QYES,
			YES
		};

		Texture top;
		Texture fill;
		Texture bottom;
		Texture nametag;

		Text text;
		Texture speaker;
		Text name;
		int16_t height;
		int16_t vtile;
		bool slider;

		TalkType type;
	};
}