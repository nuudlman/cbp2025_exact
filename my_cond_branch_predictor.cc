#include "lib/sim_common_structs.h"
#include "cbp2016_tage_sc_l.h"
#include "my_cond_branch_predictor.h"
#include <cassert>

bool EXACTPredictor::predict(uint64_t seq_no, uint8_t piece, uint64_t PC, const bool tage_pred)
{
    active_hist.tage_pred = tage_pred;
    // checkpoint current hist
    pred_time_histories.emplace(get_unique_inst_id(seq_no, piece), active_hist);
    const bool pred_taken = predict_using_given_hist(seq_no, piece, PC, active_hist, true/*pred_time_predict*/);
    return pred_taken;
}
