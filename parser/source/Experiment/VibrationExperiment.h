#ifndef VRPARSER_VIBRATIONEXPERIMENT_H
#define VRPARSER_VIBRATIONEXPERIMENT_H
#include "Experiment.h"

namespace VrParser {
    class VibrationExperiment: public Experiment {
    public:
        VibrationExperiment(const std::string& root, const int s, const int t, const std::string& v) :
            Experiment(root, s, t),
            _vib(v)
        {}

        const std::string getDataPath() const override;
        void initialize() override;
        void splitEegByMarkers(const std::string outDir);

        std::string& vib() {
            return _vib;
        }
        const std::vector<Bias>& bias() {
            return _bias;
        }

    private:
        std::string _vib;
        std::vector<Bias> _bias;
        void _init(const std::filesystem::path& dp);
        void _parseBias();
    };
}
#endif //VRPARSER_VIBRATIONEXPERIMENT_H
