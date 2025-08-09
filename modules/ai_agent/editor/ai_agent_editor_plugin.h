#ifndef AI_AGENT_EDITOR_PLUGIN_H
#define AI_AGENT_EDITOR_PLUGIN_H

#include "editor/plugins/editor_plugin.h"
#include "scene/gui/label.h"

class AIAgentEditorPlugin : public EditorPlugin {
	GDCLASS(AIAgentEditorPlugin, EditorPlugin);

	Control *dock = nullptr;
	Label *label = nullptr;

protected:
	static void _bind_methods() {}

public:
	AIAgentEditorPlugin() {}
	~AIAgentEditorPlugin() {}

	virtual String _get_plugin_name() const override { return "AI Agent"; }
	virtual bool _has_main_screen() const override { return false; }
	virtual void _enable_plugin() override {
		if (!dock) {
			dock = memnew(Control);
			label = memnew(Label);
			label->set_text("AI Agent Dock");
			dock->add_child(label);
			add_control_to_dock(DOCK_SLOT_RIGHT_UR, dock);
		}
	}
	virtual void _disable_plugin() override {
		if (dock) {
			remove_control_from_docks(dock);
			dock->queue_free();
			dock = nullptr;
			label = nullptr;
		}
	}
};

#endif // AI_AGENT_EDITOR_PLUGIN_H