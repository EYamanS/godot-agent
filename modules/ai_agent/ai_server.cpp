#include "ai_server.h"

#include "core/object/class_db.h"

AIServer *AIServer::singleton = nullptr;

void AIServer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("start_session", "config"), &AIServer::start_session);
	ClassDB::bind_method(D_METHOD("stop_session", "session"), &AIServer::stop_session);
	ClassDB::bind_method(D_METHOD("ask", "prompt", "options"), &AIServer::ask, DEFVAL(Dictionary()));
}

AIServer *AIServer::get_singleton() {
	return singleton;
}

AIServer::AIServer() {
	singleton = this;
}

AIServer::~AIServer() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

Dictionary AIServer::start_session(const Dictionary &p_config) {
	Dictionary session;
	session["id"] = (int64_t)this; // placeholder unique id
	session["active"] = true;
	return session;
}

void AIServer::stop_session(const Dictionary &p_session) {
	// placeholder
}

String AIServer::ask(const String &p_prompt, const Dictionary &p_options) {
	return String("[AIServer stub] ") + p_prompt;
}