#ifndef ONFI_SIMULATION_DATA_GENERATOR
#define ONFI_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class ONFIAnalyzerSettings;

class ONFISimulationDataGenerator
{
public:
	ONFISimulationDataGenerator();
	~ONFISimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, ONFIAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	ONFIAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //ONFI_SIMULATION_DATA_GENERATOR