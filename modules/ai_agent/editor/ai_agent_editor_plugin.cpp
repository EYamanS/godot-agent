#include "ai_agent_editor_plugin.h"

#include "editor/editor_node.h"
#include "editor/editor_plugins.h"

#ifdef TOOLS_ENABLED

static void _ai_agent_editor_init() {
	EditorPlugins::add_by_type<AIAgentEditorPlugin>();
}

#endif