package leisurejava;

import android.view.View;

public abstract interface Ihfguehfg {

	public abstract View game_plugin_get_view();
	//	游戏引擎初始化
	public abstract void game_plugin_init(int nDownloadThreadNum);

	public abstract void game_plugin_onPause();
	//	恢复前台时调用
	public abstract void game_plugin_onResume();

	//	退出游戏时 销毁
	public abstract void game_plugin_onDestory();
	//	向游戏引擎传递参数
	public abstract void game_plugin_set_option(String key, String value);
    //  设置代理对象
    public abstract void game_plugin_set_runtime_proxy(Ihfuhsefg paramIGameEngineRuntimeProxy);

}
