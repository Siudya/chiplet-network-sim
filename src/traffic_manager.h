#pragma once
#include <chrono>
#include <fstream>
#include <random>

#include "system.h"
extern "C" {
#include "netrace.h"
}
extern std::mt19937 gen;

class TrafficManager {
 public:
  TrafficManager();
  ~TrafficManager();
  void reset();
  void gen_msg(std::vector<Packet*>& packets, uint64_t cyc = 0);
  Packet* uniform_msg();
  Packet* intra_group_uniform_msg();
  Packet* hotspot_msg();
  Packet* bitcomplement_msg();
  Packet* bitreverse_msg();
  Packet* bitshuffle_msg();
  Packet* bittranspose_msg();
  Packet* adversarial_msg();
  Packet* sd_trace_msg();
  void ring_all_reduce_msg(std::vector<Packet*>& packets);
  void ring_all_reduce_bi_msg(std::vector<Packet*>& packets);
  void netrace(std::vector<Packet*>& packets, uint64_t cyc);
  inline double receiving_rate() const {
    return injection_rate_ * ((double)TM->message_arrived_ / TM->all_message_num_);
  };

  void print_statistics();

  std::fstream trace_;
  nt_context_t* CTX;
  std::fstream output_;
  std::fstream log_;

  double injection_rate_;
  inline double message_per_cycle() const {
    return injection_rate_ * traffic_scale_ / param->packet_length;
  };
  std::string traffic_;
  int traffic_scale_;
  int message_length_;

  std::unordered_map<Buffer*, std::atomic_uint64_t> traffic_map_;
  double pkt_for_injection_;
  // atomic statistics, modified by all threds
  std::chrono::system_clock::time_point time_;
  std::atomic_uint64_t all_message_num_;
  std::atomic_uint64_t message_arrived_;
  std::atomic_uint64_t message_timeout_;
  std::atomic_uint64_t total_cycles_;
  std::atomic_uint64_t total_internal_hops_;
  std::atomic_uint64_t total_parallel_hops_;
  std::atomic_uint64_t total_serial_hops_;
  std::atomic_uint64_t total_other_hops_;
};
