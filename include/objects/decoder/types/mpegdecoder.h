#pragma once

#include "objects/decoder/decoder.h"
#include "dr/dr_mp3.h"

namespace love
{
    class MPEGDecoder : public Decoder
    {
        public:
            MPEGDecoder(Data * data, int bufferSize);
            ~MPEGDecoder();

            static bool Accepts(const std::string & ext);

            Decoder * Clone();

            int Decode();

            int Decode(s16 * buffer);

            bool Seek(double position);

            bool Rewind();

            bool IsSeekable();

            int GetChannelCount() const;

            int GetBitDepth() const;

            double GetDuration();

        private:
            drmp3 mp3;
            std::vector<drmp3_seek_point> seekTable;

            double duration;
    };
}
