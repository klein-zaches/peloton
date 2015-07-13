/*-------------------------------------------------------------------------
 *
 * plan_executor.h
 * file description
 *
 * Copyright(c) 2015, CMU
 *
 * /peloton/src/backend/bridge/plan_executor.h
 *
 *-------------------------------------------------------------------------
 */

#pragma once

#include "backend/common/types.h"
#include "backend/executor/abstract_executor.h"

#include "postgres.h"
#include "access/tupdesc.h"
#include "postmaster/peloton.h"

namespace peloton {
namespace bridge {

//===--------------------------------------------------------------------===//
// Plan Executor
//===--------------------------------------------------------------------===//

class PlanExecutor {

 public:
  PlanExecutor(const PlanExecutor &) = delete;
  PlanExecutor& operator=(const PlanExecutor &) = delete;
  PlanExecutor(PlanExecutor &&) = delete;
  PlanExecutor& operator=(PlanExecutor &&) = delete;

  PlanExecutor(){};

  static void PrintPlan(const planner::AbstractPlanNode *plan, std::string prefix = "");

  static bool ExecutePlan(planner::AbstractPlanNode *plan, TupleDesc tuple_desc,
                          Peloton_Status *pstatus);

  static executor::AbstractExecutor *AddMaterialization(executor::AbstractExecutor *root);

 private:

};

} // namespace bridge
} // namespace peloton