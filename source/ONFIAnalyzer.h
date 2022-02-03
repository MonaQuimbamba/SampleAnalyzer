#ifndef ONFI_ANALYZER_H
#define ONFI_ANALYZER_H

#include <Analyzer.h>
#include "ONFIAnalyzerResults.h"
#include "ONFISimulationDataGenerator.h"

class ONFIAnalyzerSettings;
class ANALYZER_EXPORT ONFIAnalyzer : public Analyzer2
{
public:
	ONFIAnalyzer();
	virtual ~ONFIAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< ONFIAnalyzerSettings > mSettings;
	std::auto_ptr< ONFIAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	ONFISimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //ONFI_ANALYZER_H
