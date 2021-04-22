#include "objects/sounddata/sounddata.h"
#include <string>

namespace love
{
    class RecordingDevice : public Object
    {
      public:
        static love::Type type;

        static constexpr int DEFAULT_SAMPLES     = 0x2000;
        static constexpr int DEFAULT_SAMPLE_RATE = 0x1F40;
        static constexpr int DEFAULT_BIT_DEPTH   = 16;
        static constexpr int DEFAULT_CHANNELS    = 1;

        RecordingDevice();

        virtual ~RecordingDevice();

        bool Start(int samples, int sampleRate, int bitDepth, int channels);

        void Stop();

        SoundData* GetData();

        const char* GetName() const;

        int GetSampleCount() const;

        int GetMaxSamples() const;

        int GetSampleRate() const;

        int GetBitDepth() const;

        int GetChannelCount() const;

        bool IsRecording() const;
    };
} // namespace love
