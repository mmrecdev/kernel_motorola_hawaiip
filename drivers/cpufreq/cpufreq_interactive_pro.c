/*
 * Interactive CPU frequency governor for MT6765 (Helio G37)
 * Optimized for better battery life and performance
 */

#include <linux/cpufreq.h>
#include <linux/module.h>
#include <linux/slab.h>
#include "cpufreq_interactive_pro.h"

/* CPU Frequency Tables */
#define CPU_FREQ_MIN    1000000  /* 1.0 GHz */
#define CPU_FREQ_MAX    2300000  /* 2.3 GHz */
#define CPU_FREQ_IDLE   800000   /* 800 MHz */

static struct interactive_tunables tunables = {
    .hispeed_freq = 1500000,     /* 1.5 GHz */
    .go_hispeed_load = 85,       /* 85% CPU load */
    .target_loads = 80,          /* Target CPU load */
    .min_sample_time = 80000,    /* 80ms */
    .timer_rate = 20000,         /* 20ms */
};

static int cpufreq_interactive_init(struct cpufreq_policy *policy)
{
    struct interactive_policy *ipolicy;
    
    ipolicy = kzalloc(sizeof(*ipolicy), GFP_KERNEL);
    if (!ipolicy)
        return -ENOMEM;

    policy->governor_data = ipolicy;
    return 0;
}

static void cpufreq_interactive_exit(struct cpufreq_policy *policy)
{
    struct interactive_policy *ipolicy = policy->governor_data;
    
    policy->governor_data = NULL;
    kfree(ipolicy);
}

static struct cpufreq_governor cpufreq_gov_interactive_pro = {
    .name = "interactive_pro",
    .init = cpufreq_interactive_init,
    .exit = cpufreq_interactive_exit,
    .owner = THIS_MODULE,
};

static int __init cpufreq_interactive_pro_init(void)
{
    return cpufreq_register_governor(&cpufreq_gov_interactive_pro);
}

static void __exit cpufreq_interactive_pro_exit(void)
{
    cpufreq_unregister_governor(&cpufreq_gov_interactive_pro);
}

module_init(cpufreq_interactive_pro_init);
module_exit(cpufreq_interactive_pro_exit);

MODULE_AUTHOR("MrKernel");
MODULE_DESCRIPTION("Interactive CPU frequency governor for MT6765");
MODULE_LICENSE("GPL");