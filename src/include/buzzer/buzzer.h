#ifndef __BUZZER_H__
#define __BUZZER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <xboot.h>

struct buzzer_t
{
	/* The buzzer name */
	char * name;

	/* Initialize the buzzer */
	void (*init)(struct buzzer_t * buzzer);

	/* Clean up the buzzer */
	void (*exit)(struct buzzer_t * buzzer);

	/* Set buzzer's frequency, minus and zero means stop */
	void (*set)(struct buzzer_t * buzzer, int frequency);

	/* Get buzzer's frequency */
	int (*get)(struct buzzer_t * buzzer);

	/* Suspend buzzer */
	void (*suspend)(struct buzzer_t * buzzer);

	/* Resume buzzer */
	void (*resume)(struct buzzer_t * buzzer);

	/* Private data */
	void * priv;
};

struct buzzer_t * search_buzzer(const char * name);
bool_t register_buzzer(struct buzzer_t * buzzer);
bool_t unregister_buzzer(struct buzzer_t * buzzer);
void buzzer_set_frequency(struct buzzer_t * buzzer, int frequency);
int buzzer_get_frequency(struct buzzer_t * buzzer);

#ifdef __cplusplus
}
#endif

#endif /* __BUZZER_H__ */