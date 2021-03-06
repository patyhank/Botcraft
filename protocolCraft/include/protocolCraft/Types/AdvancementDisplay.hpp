#pragma once

#include "protocolCraft/NetworkType.hpp"
#include "protocolCraft/Types/Chat.hpp"
#include "protocolCraft/Types/Slot.hpp"

namespace ProtocolCraft
{
    class AdvancementDisplay : public NetworkType
    {
    public:

        void SetTitle(const Chat& title_)
        {
            title = title_;
        }

        void SetDescription(const Chat& description_)
        {
            description = description_;
        }

        void SetIcon(const Slot& icon_)
        {
            icon = icon_;
        }

        void SetFrameType(const int frame_type_)
        {
            frame_type = frame_type_;
        }

        void SetFlags(const int flags_)
        {
            flags = flags_;
        }

        void SetBackgroundTexture(const Identifier& background_texture_)
        {
            background_texture = background_texture_;
        }

        void SetXCoord(const float x_coord_)
        {
            x_coord = x_coord_;
        }
        
        void SetYCoord(const float y_coord_)
        {
            y_coord = y_coord_;
        }


        const Chat& GetTitle() const
        {
            return title;
        }

        const Chat& GetDescription() const
        {
            return description;
        }

        const Slot& GetIcon() const
        {
            return icon;
        }

        const int GetFrameType() const
        {
            return frame_type;
        }

        const int GetFlags() const
        {
            return flags;
        }
        
        const Identifier& GetBackgroundTexture() const
        {
            return background_texture;
        }

        const float GetXCoord() const
        {
            return x_coord;
        }
        
        const float GetYCoord() const
        {
            return y_coord;
        }

    protected:
        virtual void ReadImpl(ReadIterator &iter, size_t &length) override
        {
            title.Read(iter, length);
            description.Read(iter, length);
            icon.Read(iter, length);
            frame_type = ReadVarInt(iter, length);
            flags = ReadData<int>(iter, length);
            if (flags & 0x01)
            {
                background_texture = ReadString(iter, length);
            }
            x_coord = ReadData<float>(iter, length);
            y_coord = ReadData<float>(iter, length);
        }

        virtual void WriteImpl(WriteContainer &container) const override
        {
            title.Write(container);
            description.Write(container);
            icon.Write(container);
            WriteVarInt(frame_type, container);
            WriteData<int>(flags, container);
            if (flags & 0x01)
            {
                WriteString(background_texture, container);
            }
            WriteData<float>(x_coord, container);
            WriteData<float>(y_coord, container);
        }

        virtual const picojson::value SerializeImpl() const override
        {
            picojson::value value(picojson::object_type, false);
            picojson::object& object = value.get<picojson::object>();

            object["title"] = title.Serialize();
            object["description"] = description.Serialize();
            object["icon"] = icon.Serialize();
            object["frame_type"] = picojson::value((double)frame_type);
            object["flags"] = picojson::value((double)flags);
            if (flags & 0x01)
            {
                object["background_texture"] = picojson::value(background_texture);
            }
            object["x_coord"] = picojson::value((double)x_coord);
            object["y_coord"] = picojson::value((double)y_coord);

            return value;
        }

    private:
        Chat title;
        Chat description;
        Slot icon;
        int frame_type;
        int flags;
        Identifier background_texture;
        float x_coord;
        float y_coord;
    };
}