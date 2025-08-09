#ifndef AI_SERVER_H
#define AI_SERVER_H

#include "core/object/object.h"
#include "core/object/ref_counted.h"
#include "core/variant/dictionary.h"
#include "core/object/class_db.h"

class AIServer : public Object {
	GDCLASS(AIServer, Object);

private:
	static AIServer *singleton;

protected:
	static void _bind_methods();

public:
	static AIServer *get_singleton();

	AIServer();
	~AIServer();

	Dictionary start_session(const Dictionary &p_config);
	void stop_session(const Dictionary &p_session);
	String ask(const String &p_prompt, const Dictionary &p_options = Dictionary());
};

#endif // AI_SERVER_H