#ifndef EXACTPREDICTOR_H
#define EXACTPREDICTOR_H

#include <cstdint>

enum class PredictorChoice : uint8_t
{
    Tage,
    EXACT
};

/// Unlimited EXACT Predictor
/// https://dl.acm.org/doi/10.1145/1787275.1787321
/// @author Isaac Nudelman
class EXACTPredictor
{
public:
    EXACTPredictor() = default;
    ~EXACTPredictor() = default;


    /// The chooser has three jobs: 1) identify branches that are best
    /// predicted by the default predictor (§3.6.1), 2) identify branches that
    /// exhibit dynamic trip-counts, hence, are best predicted by the explicit
    /// loop predictor if it hits or the default predictor otherwise (§3.6.2),
    /// and 3) identify branches that do not need global branch history
    /// included in their indices (§3.6.3).
    ///
    /// The chooser is PC-indexed and is not tagged. Thus, classification is
    /// on a per-static-branch basis. This is not only efficient in terms of
    /// storage but it also enables rapid classification since all dynamic
    /// instances of a static branch train its entry.
    PredictorChoice choose(uint64_t seq_no, uint8_t piece, uint64_t pc, uint64_t pred_cycle) const;

private:
    /// A dynamic branch forms its ID by hashing its PC and load addresses
    /// together, as follows. The first address is XORed with the second
    /// address shifted left by one bit, the third address shifted left by two
    /// bits, and so on, for as many load addresses as there are. The result is
    /// then ANDed with a mask to extract the low N bits, for an explicit
    /// predictor that has 2N entries. The upper 8 bits of the result is XORed
    /// with the lower 8 bits of the PC.
    static uint64_t id(uint64_t pc, uint64_t load_addr);
};



#endif //EXACTPREDICTOR_H
