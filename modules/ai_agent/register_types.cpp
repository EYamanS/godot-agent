#include "register_types.h"

#include "core/config/engine.h"
#include "core/object/class_db.h"

#include "ai_server.h"

#ifdef TOOLS_ENABLED
#include "editor/plugins/editor_plugin.h"
#include "editor/editor_plugins.h"
#include "editor/ai_agent_editor_plugin.h"
#endif

static AIServer *ai_server_singleton = nullptr;

void initialize_ai_agent_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_CORE) {
		GDREGISTER_CLASS(AIServer);
	}
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		ai_server_singleton = memnew(AIServer);
		Engine::get_singleton()->add_singleton(Engine::Singleton("AIServer", ai_server_singleton));
	}
#ifdef TOOLS_ENABLED
	if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		EditorPlugins::add_by_type<AIAgentEditorPlugin>();
	}
#endif
}

void uninitialize_ai_agent_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		if (ai_server_singleton) {
			memdelete(ai_server_singleton);
			ai_server_singleton = nullptr;
		}
	}
}