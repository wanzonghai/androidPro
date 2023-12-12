#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct VirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
struct InvokerActionInvoker0
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj)
	{
		method->invoker_method(methodPtr, method, obj, NULL, NULL);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// System.Action`1<UnityEngine.AsyncOperation>
struct Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB;
// System.Action`1<System.Object>
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
// System.Action`1<UnityEngine.WWW>
struct Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF;
// BaseManager`1<CardManager>
struct BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936;
// BaseManager`1<EventCenter>
struct BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19;
// BaseManager`1<EventDispatcher>
struct BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2;
// BaseManager`1<GameData>
struct BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1;
// BaseManager`1<InputMgr>
struct BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E;
// BaseManager`1<MonoMgr>
struct BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161;
// BaseManager`1<MusicMgr>
struct BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863;
// BaseManager`1<System.Object>
struct BaseManager_1_t05610E014301ECCB96A1DB8F51E4D6C3A23EAD39;
// BaseManager`1<PoolManage>
struct BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93;
// BaseManager`1<PoolMgr>
struct BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330;
// BaseManager`1<ResMgr>
struct BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951;
// BaseManager`1<ScenesMgr>
struct BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3;
// BaseManager`1<TextureMgr>
struct BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF;
// BaseManager`1<TimerMgr>
struct BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7;
// BaseManager`1<Tools>
struct BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF;
// BaseManager`1<UIManager>
struct BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B;
// System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>>
struct Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E;
// System.Comparison`1<System.Object>
struct Comparison_1_t62E531E7B8260E2C6C2718C3BDB8CF8655139645;
// System.Comparison`1<UnityEngine.EventSystems.RaycastResult>
struct Comparison_1_t9FCAC8C8CE160A96C5AAD2DE1D353DCE8A2FEEFC;
// System.Runtime.CompilerServices.ConditionalWeakTable`2<System.Object,System.Runtime.Serialization.SerializationInfo>
struct ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>
struct Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>
struct Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907;
// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.Sprite>
struct Dictionary_2_tD001156821253ED04A22112577C96EFE869F40F0;
// System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>
struct Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF;
// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>
struct Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84;
// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>
struct Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26;
// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>
struct Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19;
// System.Collections.Generic.Dictionary`2<System.String,BasePanel>
struct Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294;
// System.Collections.Generic.Dictionary`2<System.String,IEventInfo>
struct Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874;
// System.Collections.Generic.Dictionary`2<System.String,PoolData>
struct Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5;
// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>
struct Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516;
// System.Collections.Generic.IDictionary`2<System.Int32,System.Int32>
struct IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E;
// System.Collections.Generic.IEnumerable`1<System.Int32>
struct IEnumerable_1_tCE758D940790D6D0D56B457E522C195F8C413AF2;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
// System.Collections.Generic.IEqualityComparer`1<System.String>
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
// System.Collections.Generic.IList`1<System.Collections.Generic.IList`1<System.Int32>>
struct IList_1_t1BFB14A37E343598359F66561A76310947DDAB4E;
// System.Collections.Generic.IList`1<System.Int32>
struct IList_1_tFB8BE2ED9A601C1259EAB8D73D1B3E96EA321FA1;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,System.Delegate>
struct KeyCollection_tCE5BFB45C1AADA55E240384E2C7D67E1BD5F9B92;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,System.Int32>
struct KeyCollection_t67E8423B5AEB30C254013AD88AB68D2A36F1F436;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,TimerNode>
struct KeyCollection_tDAEC9F114372256CF4845EC56F6C5C53ED1428AD;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>
struct KeyCollection_t0067DBA51C244DFFA49917D4BAC28F9BD27011BB;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>
struct KeyCollection_tE594E767AFE3919BFD74EBC9FF74EC296A197F38;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,UnityEngine.Object[]>
struct KeyCollection_tF3F05788E88EA577CC5900CC3ED49159A87AF3C7;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,BasePanel>
struct KeyCollection_t4CB612A4FA927C74BFEAFA7ACDC4F5C6AB0468C0;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,IEventInfo>
struct KeyCollection_t94E0B3EE8935A1E203883D261B3EF75071DE2F07;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,PoolData>
struct KeyCollection_tD45C415B78A56714F7B98112FF764965ADD10F8B;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,UnityEngine.Sprite>
struct KeyCollection_t138136109408FD98DBF627F9E05EA32CBF0D9893;
// System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>
struct List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77;
// System.Collections.Generic.List`1<UnityEngine.AudioClip>
struct List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F;
// System.Collections.Generic.List`1<UnityEngine.AudioSource>
struct List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseInputModule>
struct List_1_tA5BDE435C735A082941CD33D212F97F4AE9FA55F;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventSystem>
struct List_1_tF2FE88545EFEC788CAAE6C74EC2F78E937FCCAC3;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B;
// System.Collections.Generic.List`1<UnityEngine.UI.Image>
struct List_1_tE6BB71ABF15905EFA2BE92C38A2716547AEADB19;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<TimerNode>
struct List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5;
// System.Predicate`1<UnityEngine.AudioClip>
struct Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6;
// System.Predicate`1<System.Object>
struct Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>
struct UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6;
// UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>
struct UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187;
// UnityEngine.Events.UnityAction`1<System.Object>
struct UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Delegate>
struct ValueCollection_tBF843AA91F5FA1EA2A9A03D93D5DB0FFDEF0A39F;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Int32>
struct ValueCollection_t74AF7C1BAE06C66E984668F663D574ED6A596D28;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Object>
struct ValueCollection_t65BBB6F728D41FD4760F6D6C59CC030CF237785F;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,TimerNode>
struct ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>
struct ValueCollection_tDFF561CE8EEE08EBF70B478426EB365DBA90639A;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>
struct ValueCollection_t06E4AB75C64B59EDD2285FA5D53B0A560E89EA9E;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.Object[]>
struct ValueCollection_tB110CB16196410A3935AFFAD07E34A0A22B969E4;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,BasePanel>
struct ValueCollection_tE04C716D1CB0DEF47A65EF2B15BD412E8CFD3484;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,IEventInfo>
struct ValueCollection_tE7D86AE11A65A266964F1A1FB24FC2DA21C5003F;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,PoolData>
struct ValueCollection_t802332022104D9D0E75232111A429D4599BEFE49;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.Sprite>
struct ValueCollection_t64BF35FAA59E1267E091C891F36E42D7AE38CFE3;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,System.Delegate>[]
struct EntryU5BU5D_t3736DB30B8164DCE7F263708DD34E40C88E3C9C7;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,System.Int32>[]
struct EntryU5BU5D_t197C691F43F1694B771BF83C278D12BBFEEB86FA;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,TimerNode>[]
struct EntryU5BU5D_tA8305A5641ECC320868AE49BAC13D5D24961425B;
// System.Collections.Generic.Dictionary`2/Entry<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>[]
struct EntryU5BU5D_tB38F95D9E9B3F10E7869115FED7EE71B1C9ECD07;
// System.Collections.Generic.Dictionary`2/Entry<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>[]
struct EntryU5BU5D_t7784AD1CBABF85A513CD7BAC09391E39AAA70A7D;
// System.Collections.Generic.Dictionary`2/Entry<System.String,UnityEngine.Object[]>[]
struct EntryU5BU5D_tA3FFC85BF9D4C963A5D323F2CDC43CDB3381A07A;
// System.Collections.Generic.Dictionary`2/Entry<System.String,BasePanel>[]
struct EntryU5BU5D_t7F2D0C639A5964C45C89C4FEC5767FA880494D00;
// System.Collections.Generic.Dictionary`2/Entry<System.String,IEventInfo>[]
struct EntryU5BU5D_t7538D36A574F3AA0DCF77430FE5FB8D307D0E1D3;
// System.Collections.Generic.Dictionary`2/Entry<System.String,PoolData>[]
struct EntryU5BU5D_t014B0C9084FC234C4E1A0E190D55736E0BE70CA9;
// System.Collections.Generic.Dictionary`2/Entry<System.String,UnityEngine.Sprite>[]
struct EntryU5BU5D_t1B7F4FC29B23EAA2C5A6E9B695B79119DE17DCAE;
// System.Collections.Generic.IList`1<System.Int32>[]
struct IList_1U5BU5D_t80E946F93A165B207DCC681025281F722B753D2A;
// System.Int32[][]
struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E;
// UnityEngine.AudioClip[]
struct AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31;
// UnityEngine.AudioSource[]
struct AudioSourceU5BU5D_tBBF6E920E0DC80D53D4BB2A8D4C80D244EF170B2;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// UnityEngine.GameObject[]
struct GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF;
// UnityEngine.UI.Image[]
struct ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// UnityEngine.Object[]
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A;
// UnityEngine.Sprite[]
struct SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// TimerNode[]
struct TimerNodeU5BU5D_t87E8231726A789A53902D248822EF9E7F4A6DF2D;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// System.Collections.Hashtable/bucket[]
struct bucketU5BU5D_t59F1C7BC4EBFE874CA0B3F391EA65717E3C8D587;
// Act
struct Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE;
// AndroidJavaCShap
struct AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19;
// UnityEngine.AndroidJavaClass
struct AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03;
// UnityEngine.AndroidJavaObject
struct AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0;
// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C;
// UnityEngine.AudioClip
struct AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20;
// UnityEngine.AudioSource
struct AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F;
// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1;
// BasePanel
struct BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// CardManager
struct CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// EventCenter
struct EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170;
// EventDispatcher
struct EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB;
// EventInfo
struct EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707;
// UnityEngine.UI.FontData
struct FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224;
// GameData
struct GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// UnityEngine.GlobalJavaObjectRef
struct GlobalJavaObjectRef_t20D8E5AAFC2EB2518FCABBF40465855E797FF0D8;
// HallScene
struct HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C;
// System.Collections.Hashtable
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// System.Collections.ICollection
struct ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// System.Collections.IEqualityComparer
struct IEqualityComparer_tEF8F1EC76B9C8E76695BE848D41E6B147928D1C1;
// IEventInfo
struct IEventInfo_t63E83A0BD5575F469348CA58617F41236CE69A79;
// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E;
// InputMgr
struct InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C;
// LoadScene
struct LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// MonoController
struct MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8;
// MonoMgr
struct MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47;
// MusicMgr
struct MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// PoolData
struct PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6;
// PoolManage
struct PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266;
// PoolMgr
struct PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F;
// System.Random
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// ResManage
struct ResManage_t5FAD4C5CBE0C758E708AF91991FD5E103F61E127;
// ResMgr
struct ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482;
// ResourcesLoadingMode
struct ResourcesLoadingMode_tBB229B38FF898346D20A767694266251D16C2048;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// ScenesMgr
struct ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F;
// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99;
// System.String
struct String_t;
// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62;
// UnityEngine.TextGenerator
struct TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// TextureMgr
struct TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901;
// TimerMgr
struct TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A;
// TimerNode
struct TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7;
// Tools
struct Tools_t3DF42EB905CE903A075617859FA36803BEC507C4;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// UIManager
struct UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// UnityEngine.Networking.UnityWebRequest
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.WWW
struct WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB;
// UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3;
// UnityEngine.AudioClip/PCMReaderCallback
struct PCMReaderCallback_t3396D9613664F0AFF65FB91018FD0F901CC16F1E;
// UnityEngine.AudioClip/PCMSetPositionCallback
struct PCMSetPositionCallback_t8D7135A2FB40647CAEC93F5254AD59E18DEB6072;
// HallScene/<ShowStartObj>d__25
struct U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41;
// LoadScene/<ShowStartObj>d__10
struct U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// MusicMgr/<>c__DisplayClass11_0
struct U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1;
// PoolMgr/<>c__DisplayClass2_0
struct U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF;
// UnityEngine.RectTransform/ReapplyDrivenProperties
struct ReapplyDrivenProperties_t3482EA130A01FF7EE2EEFE37F66A5215D08CFE24;
// ResManage/<WWWLoad>d__3
struct U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C;
// ScenesMgr/<ReallyLoadSceneAsyn>d__2
struct U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A;
// TimerMgr/TimerHandler
struct TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23;
// Tools/<>c
struct U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290;

IL2CPP_EXTERN_C RuntimeClass* Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICollection_1_tC5372778958BA5852D51B60DE91458957B103012_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_1_t702400094DFC0F9AF0893F00166C2C1632C01819_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_1_t0003EC9F1922ECBB54EB7E71B85E13FBC8357DD6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IList_1_tFB8BE2ED9A601C1259EAB8D73D1B3E96EA321FA1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral02AAF53D94E93084B4B52EF4C1C98D9C7E4D02B4;
IL2CPP_EXTERN_C String_t* _stringLiteral039B89BE7F0419C65251684D8479CFFBEB3B15E2;
IL2CPP_EXTERN_C String_t* _stringLiteral17FC0954E2BA29F862AC82AAF54615D8CF0A5190;
IL2CPP_EXTERN_C String_t* _stringLiteral2064F80F811DB79A33C4E51C10221454E30C74AE;
IL2CPP_EXTERN_C String_t* _stringLiteral21ED4C7AF50D987589A9029FC0422151BE3A0FC2;
IL2CPP_EXTERN_C String_t* _stringLiteral23EB829BB546619387DBE1C61ED5889563B83EA4;
IL2CPP_EXTERN_C String_t* _stringLiteral2AD9F8D8C3A372CA0039306F13BEDA0B460207C8;
IL2CPP_EXTERN_C String_t* _stringLiteral36A288CB98EAA1C50F7B49BAB05E2F6C164F41DA;
IL2CPP_EXTERN_C String_t* _stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63;
IL2CPP_EXTERN_C String_t* _stringLiteral422457F901751FA3B57100A103387F681147FE63;
IL2CPP_EXTERN_C String_t* _stringLiteral467E141EA4AD8622B0ACCD7E96619F6FDC12DD21;
IL2CPP_EXTERN_C String_t* _stringLiteral49C2C4CBD74690CC3F0B4127393BEA222F0A5B31;
IL2CPP_EXTERN_C String_t* _stringLiteral4B21C6381F4562924241036A9190E1FD19FD99B2;
IL2CPP_EXTERN_C String_t* _stringLiteral4CEA8A0063213A8412FA6B1C943CA05E38FD880E;
IL2CPP_EXTERN_C String_t* _stringLiteral4D2404A81DE320C8F8813DF7EA8F5B10E6FAD2EB;
IL2CPP_EXTERN_C String_t* _stringLiteral5DB596466906579C0A69E299AFF6AE1ABC42D9F1;
IL2CPP_EXTERN_C String_t* _stringLiteral61E694FFA1F9C158F5F7ADB738F4D38EAE670E74;
IL2CPP_EXTERN_C String_t* _stringLiteral6AEF201C57685514EF3E2DA0F18AE2E224BEAD5D;
IL2CPP_EXTERN_C String_t* _stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743;
IL2CPP_EXTERN_C String_t* _stringLiteral6E3E0318C851B84A160E7BB95BCF95485620A391;
IL2CPP_EXTERN_C String_t* _stringLiteral6F8680E036372B06F0D00587303C00203DFE6F0D;
IL2CPP_EXTERN_C String_t* _stringLiteral719F762A86CD14403E2AE40F2B708BA434A967A2;
IL2CPP_EXTERN_C String_t* _stringLiteral7454695E25D304C65D0C1333D8008E862569CAE9;
IL2CPP_EXTERN_C String_t* _stringLiteral75BA92A17A01F0E039DA3C7128CDA319E62D1F62;
IL2CPP_EXTERN_C String_t* _stringLiteral8203E97DE0174CAD29A442EADB89EBE0C1A2ED68;
IL2CPP_EXTERN_C String_t* _stringLiteral8ADBEED1B1F615476CC36A651CA71118DDF9447D;
IL2CPP_EXTERN_C String_t* _stringLiteral8CBC0B20B7980F8F53D0AAAAD321F93E251E1FA1;
IL2CPP_EXTERN_C String_t* _stringLiteralB3C34217CBB8F650ED8F6E70B410A604371E2EF1;
IL2CPP_EXTERN_C String_t* _stringLiteralBD02D6E0891A74DFC91263FF3056D5D5BD982D91;
IL2CPP_EXTERN_C String_t* _stringLiteralC20F0AF5CF583A987CF53E1C5B19E24CA620A7D2;
IL2CPP_EXTERN_C String_t* _stringLiteralC3B5254FCC61D515E7907085297D572F36351F06;
IL2CPP_EXTERN_C String_t* _stringLiteralC4DC1E9A8507E97CD9B7016D8AF01F02FF133A0C;
IL2CPP_EXTERN_C String_t* _stringLiteralCB26D0F80C241D4EA4617B2C4982285182E48882;
IL2CPP_EXTERN_C String_t* _stringLiteralD0B7C5B0A0F6BAC914AB8AF13D0CC0A273F0A51D;
IL2CPP_EXTERN_C String_t* _stringLiteralD16E68047D3CA19D8302E86499BBAAFB39246C53;
IL2CPP_EXTERN_C String_t* _stringLiteralD3C6FF105F16F36B05CE62DC0895F7A6B90F6ED8;
IL2CPP_EXTERN_C String_t* _stringLiteralD620A361DDE79216C95A8EB1682325D49CFFEB33;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralE9145F1641B02E019012EA10F0841B203C5B880F;
IL2CPP_EXTERN_C String_t* _stringLiteralE91FE173F59B063D620A934CE1A010F2B114C1F3;
IL2CPP_EXTERN_C String_t* _stringLiteralED1214349048E77894291A17B22CFB3D36649C9D;
IL2CPP_EXTERN_C String_t* _stringLiteralF7ABB51D46C7E6D807C6F4DEB4C79449E27350C0;
IL2CPP_EXTERN_C String_t* _stringLiteralFD287904696D646E8D7141244D9557B0C6F5D003;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Dispose_mA0466D2F6A65CDCB41846E8C8A5AAF739E38CA53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Getinstance_m5F6E80E4D3876B809AAA9A749CE6A07FC7C6336D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m10373C1881893A2C205BE38BF428C64D736D3F88_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m12855CB17B210C30B34A51A5F46133DC89EC1143_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m281F94215DC637D51B8209FC887A679AB62DBF72_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m3B392CE03E1272ECCA3572C2636F6B8164800BF4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m447D12F4D58984A74CEC8FBA40A2134E96AC612A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m77C93A4EE16FCB481F59FCF871382DFB8C142CAA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m783192CA846185C692F3A4D5EF88408EBD62E85E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m8062140E42661EB2AB4A1030F79D18744A4B8588_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_m90F17B40FD5672642AAA8231A17565250792C81D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mA6B8F030965B62068872EE479BB3B09A3732A1E1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mB0C3F10038D85090EF52704CF110118CE22F9F91_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mBCB1DDC744D6A952DA9059FAF2B78CD80D0B17A0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mDC5FD6061CABB05CC105C36E9311336DD2BDCF0C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mEE6B30A7F62B93E4D5B5820A8D7FE5DE12CADA5D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseManager_1__ctor_mF24449044241FBE79F9117BCEFA3220A9B495B53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisButton_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098_m029C39C826883D2524CA863001E667E87BE409A1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m47A1C2FF88A2A26CC43096D6216E399FCD8A6A7D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisInputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_m343137C9C44061BD062868342886A83C5273ECAB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisScrollRect_t17D2F2939CA8953110180DF53164CFC3DC88D70E_m9B6EADB8778BB07A420D8AEF2E0FB30962AD2BBF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisSlider_t87EA570E3D6556CABF57456C2F3873FFD86E652F_mA085184DD785D57BD63A352B6E5E204B60AABED2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisText_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_m63245651BC205E8B7F07C02C05599F40069ACC98_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BasePanel_FindChildrenControl_TisToggle_tBF13F3EBA485E06826FD8A38F4B4C1380DF21A1F_m43CBE6D9B457660C66048941ECE7D9D4567B9ADF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m42DA4DEA19EB60D80CBED7413ADEB27FA033C77B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m02206C3B3DE104D0979A83B82914DD1E55287DFD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m262241C63CA5FD4C4C40338008DD2097E94E6222_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m9AFDA112B11C0CD915081B9B2DF3B78C84CD82E8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mB7B8E9E63DD9C59E6683CFF7D32E372F86029A5B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mC87FA1BC7656A1A1B43AEC922DB326EE287988C9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Clear_m01EBB27E251F4438920D9DAB786F4A20E28EA82F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Clear_m08917F7954D626ED30A494E9127F69C3002BE29A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Clear_m8EC60FC45B7B894CCEF267E8D0A3DBA52A7897FF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m1711AF6E4992D16A259079D27B3B190A2E0641D3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m67CC65BB4A27FA582E357743809FD05E546E0C60_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_mE7FD7A2EF471213473524B8051F0B27059B3E9F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_m1F5269D68341155CEFF355916ED98C36FB157D29_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_m37200A4980CCA1989CFE0A913D65F5B9D8E507D3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_mCE9DE052A13E9FF30C3200B08CE80100D8DB09C5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m09BE4980B91235B1F22BBDFADADED0AFE80CEB53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m5700B41402680D1EF55FD8A6B8ED41D348D9B83B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m8ADA5D11C145B740261CF875F392AF711FE1423C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mA1D9EB14DD67356C94A0C1717D80F18979B839C0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mC3BBDDAFE2FBCB7710787DE56899D4E6BCD9C0A2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mDAFC0246415FCD20B4DFA892990A1AAA6F27C334_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mE45CA150515955650A183C2827A3DA3A8770F80D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mE4874F66ADA7FCBE7FB1BEDBA767DCEC3CCDF624_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mFAF8880680AB14AC23BE7F389E98862841A59CE9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_m779DD6A6BA1E9FA43761E654977AE8C9CC45FF34_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_mBA8590162AAF64A9FEA05B610BCDCB7904D55587_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_mC4807C8F26B84E5B332C4BD38978B9D8E3DF740D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Values_m88D0B7D51A606222E4BBAFF146B77772E5491B7E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_mD460E52E10776520A9AD30A2BF1ED4E06F398727_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_mA4BD3457EF4189DB8017D964A865BF98CE30DEC9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m8172A0F32B0FD2CB250B2F7E9B1B4ED285A0E4CF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m92C769426ADE52700E4F8E40760D6F8FAED469ED_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_AddComponent_TisMonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8_mB2196B16A7FFE8997D15F0C33A4334876F1BA9E7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m4F30DAB8E5B57E8DB6BD8C0C3BB11CCB57690C4A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* InputMgr_MyUpdate_mE872B96792B1BC670AA4A3B212FDEFD12ABE0084_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m51C49FD07D05048E52C4324E83FEC9BD2174F6B7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m854AB1F4912F4A70C478FAE8E282C8F6CE880550_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Contains_m85C62F7184BE9A0919BFBB82DE91D6C4AB143BD6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Find_m7D74D30D22001969B022341FCB9E7BB633C9638F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_m023E515689BBE45DA9EE94BE763578B854A74CF2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Remove_m7F54CE1C95A107E8F4A696104788E78107528DDB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Sort_m0325E504A9F068571CDFAC2F69891902A1A7A263_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m1572AF991CD3CD21B43B0D6F699FE6296DEDF9E7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m34392E0322B2071E67CE2DE1218585334AF12271_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m985F72633850464A3301F658B9CD510F7ADCDC33_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MusicMgr_Update_m4D7AD42E819A73E226CE0582614CAB91B584A6FC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m10D87C6E0708CA912BBB02555BF7D0FBC5D7A2B3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ResMgr_LoadAll_TisAudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20_m0E51BEBC9135361F746488BE347CCF40C71FE769_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ResMgr_LoadAsync_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_mAAEEB26879FEB6A44035D9B29A86CDEC4013F84F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Resources_LoadAll_TisSprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_m5AB56F241D4637483AB93C9A1AADA0A304C8607E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Resources_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m496A3B1B60A28F5E0397043974B848C9157B625A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Tools_GenerateRandomUniqueData_m49423BF22EDBF1C0EC492FB427AF60F1CD0E99BF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CReallyLoadSceneAsynU3Ed__2_System_Collections_IEnumerator_Reset_m24991A1FD836CB9F9CC969577E9B492B82F5D1F5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CShowStartObjU3Ed__10_System_Collections_IEnumerator_Reset_m88DE256B46F127FD65E87558C3019A08737B3675_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CShowStartObjU3Ed__25_System_Collections_IEnumerator_Reset_m4FAE2B3698E68C6ACB1C36CAE49DDF933BD70068_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3CMergeSimilarItemsU3Eb__2_0_mA38BB2AED2FAE883FE0A20D946ED768404156C73_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec__DisplayClass11_0_U3CGetAudioClipByNameU3Eb__0_m9228114D053677A9B9902C7BA0C03E9BFA65DAB9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec__DisplayClass2_0_U3CGetObjU3Eb__0_mAC15ECEB39E40CD3936C8B2650E7A84A85D9625F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CWWWLoadU3Ed__3_System_Collections_IEnumerator_Reset_mA2FEBCB5274E7C74F23470B61C0ECBE9C17CE8DA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ValueCollection_GetEnumerator_mA8242DA37C7181A80FCEEB7535CA464991FC2C17_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E;
struct AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A;
struct SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_tBB65183F1134474D09FF49B95625D25472B9BA8B 
{
};

// BaseManager`1<CardManager>
struct BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936  : public RuntimeObject
{
};

// BaseManager`1<EventCenter>
struct BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19  : public RuntimeObject
{
};

// BaseManager`1<EventDispatcher>
struct BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2  : public RuntimeObject
{
};

// BaseManager`1<GameData>
struct BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1  : public RuntimeObject
{
};

// BaseManager`1<InputMgr>
struct BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E  : public RuntimeObject
{
};

// BaseManager`1<MonoMgr>
struct BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161  : public RuntimeObject
{
};

// BaseManager`1<MusicMgr>
struct BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863  : public RuntimeObject
{
};

// BaseManager`1<PoolManage>
struct BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93  : public RuntimeObject
{
};

// BaseManager`1<PoolMgr>
struct BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330  : public RuntimeObject
{
};

// BaseManager`1<ResMgr>
struct BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951  : public RuntimeObject
{
};

// BaseManager`1<ScenesMgr>
struct BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3  : public RuntimeObject
{
};

// BaseManager`1<TextureMgr>
struct BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF  : public RuntimeObject
{
};

// BaseManager`1<TimerMgr>
struct BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7  : public RuntimeObject
{
};

// BaseManager`1<Tools>
struct BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF  : public RuntimeObject
{
};

// BaseManager`1<UIManager>
struct BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B  : public RuntimeObject
{
};

// System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>
struct Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t3736DB30B8164DCE7F263708DD34E40C88E3C9C7* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tCE5BFB45C1AADA55E240384E2C7D67E1BD5F9B92* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tBF843AA91F5FA1EA2A9A03D93D5DB0FFDEF0A39F* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>
struct Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t197C691F43F1694B771BF83C278D12BBFEEB86FA* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t67E8423B5AEB30C254013AD88AB68D2A36F1F436* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t74AF7C1BAE06C66E984668F663D574ED6A596D28* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>
struct Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tA8305A5641ECC320868AE49BAC13D5D24961425B* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tDAEC9F114372256CF4845EC56F6C5C53ED1428AD* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>
struct Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tB38F95D9E9B3F10E7869115FED7EE71B1C9ECD07* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t0067DBA51C244DFFA49917D4BAC28F9BD27011BB* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tDFF561CE8EEE08EBF70B478426EB365DBA90639A* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>
struct Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t7784AD1CBABF85A513CD7BAC09391E39AAA70A7D* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tE594E767AFE3919BFD74EBC9FF74EC296A197F38* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t06E4AB75C64B59EDD2285FA5D53B0A560E89EA9E* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>
struct Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tA3FFC85BF9D4C963A5D323F2CDC43CDB3381A07A* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tF3F05788E88EA577CC5900CC3ED49159A87AF3C7* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tB110CB16196410A3935AFFAD07E34A0A22B969E4* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,BasePanel>
struct Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t7F2D0C639A5964C45C89C4FEC5767FA880494D00* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t4CB612A4FA927C74BFEAFA7ACDC4F5C6AB0468C0* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tE04C716D1CB0DEF47A65EF2B15BD412E8CFD3484* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,IEventInfo>
struct Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t7538D36A574F3AA0DCF77430FE5FB8D307D0E1D3* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t94E0B3EE8935A1E203883D261B3EF75071DE2F07* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tE7D86AE11A65A266964F1A1FB24FC2DA21C5003F* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,PoolData>
struct Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t014B0C9084FC234C4E1A0E190D55736E0BE70CA9* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tD45C415B78A56714F7B98112FF764965ADD10F8B* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t802332022104D9D0E75232111A429D4599BEFE49* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>
struct Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t1B7F4FC29B23EAA2C5A6E9B695B79119DE17DCAE* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t138136109408FD98DBF627F9E05EA32CBF0D9893* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t64BF35FAA59E1267E091C891F36E42D7AE38CFE3* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.EmptyArray`1<System.Object>
struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE  : public RuntimeObject
{
};

// System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>
struct List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	IList_1U5BU5D_t80E946F93A165B207DCC681025281F722B753D2A* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<UnityEngine.AudioClip>
struct List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<UnityEngine.AudioSource>
struct List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	AudioSourceU5BU5D_tBBF6E920E0DC80D53D4BB2A8D4C80D244EF170B2* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<TimerNode>
struct List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	TimerNodeU5BU5D_t87E8231726A789A53902D248822EF9E7F4A6DF2D* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,TimerNode>
struct ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97  : public RuntimeObject
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection::_dictionary
	Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* ____dictionary_0;
};

// UnityEngine.AndroidJavaObject
struct AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0  : public RuntimeObject
{
	// UnityEngine.GlobalJavaObjectRef UnityEngine.AndroidJavaObject::m_jobject
	GlobalJavaObjectRef_t20D8E5AAFC2EB2518FCABBF40465855E797FF0D8* ___m_jobject_1;
	// UnityEngine.GlobalJavaObjectRef UnityEngine.AndroidJavaObject::m_jclass
	GlobalJavaObjectRef_t20D8E5AAFC2EB2518FCABBF40465855E797FF0D8* ___m_jclass_2;
};

// UnityEngine.CustomYieldInstruction
struct CustomYieldInstruction_t6B81A50D5D210C1ACAAE247FB53B65CDFFEB7617  : public RuntimeObject
{
};

// EventInfo
struct EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9  : public RuntimeObject
{
	// UnityEngine.Events.UnityAction EventInfo::actions
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___actions_0;
};

// System.Collections.Hashtable
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D  : public RuntimeObject
{
	// System.Collections.Hashtable/bucket[] System.Collections.Hashtable::_buckets
	bucketU5BU5D_t59F1C7BC4EBFE874CA0B3F391EA65717E3C8D587* ____buckets_10;
	// System.Int32 System.Collections.Hashtable::_count
	int32_t ____count_11;
	// System.Int32 System.Collections.Hashtable::_occupancy
	int32_t ____occupancy_12;
	// System.Int32 System.Collections.Hashtable::_loadsize
	int32_t ____loadsize_13;
	// System.Single System.Collections.Hashtable::_loadFactor
	float ____loadFactor_14;
	// System.Int32 modreq(System.Runtime.CompilerServices.IsVolatile) System.Collections.Hashtable::_version
	int32_t ____version_15;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Collections.Hashtable::_isWriterInProgress
	bool ____isWriterInProgress_16;
	// System.Collections.ICollection System.Collections.Hashtable::_keys
	RuntimeObject* ____keys_17;
	// System.Collections.ICollection System.Collections.Hashtable::_values
	RuntimeObject* ____values_18;
	// System.Collections.IEqualityComparer System.Collections.Hashtable::_keycomparer
	RuntimeObject* ____keycomparer_19;
	// System.Object System.Collections.Hashtable::_syncRoot
	RuntimeObject* ____syncRoot_20;
};

// PoolData
struct PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6  : public RuntimeObject
{
	// UnityEngine.GameObject PoolData::fatherObj
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___fatherObj_0;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> PoolData::poolList
	List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ___poolList_1;
};

// System.Random
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8  : public RuntimeObject
{
	// System.Int32 System.Random::_inext
	int32_t ____inext_0;
	// System.Int32 System.Random::_inextp
	int32_t ____inextp_1;
	// System.Int32[] System.Random::_seedArray
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____seedArray_2;
};

// ResourcesLoadingMode
struct ResourcesLoadingMode_tBB229B38FF898346D20A767694266251D16C2048  : public RuntimeObject
{
	// UnityEngine.UI.Image ResourcesLoadingMode::Img
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ___Img_0;
	// UnityEngine.MonoBehaviour ResourcesLoadingMode::MB
	MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* ___MB_1;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// TimerNode
struct TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7  : public RuntimeObject
{
	// TimerMgr/TimerHandler TimerNode::callback
	TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* ___callback_0;
	// System.Single TimerNode::repeatRate
	float ___repeatRate_1;
	// System.Single TimerNode::time
	float ___time_2;
	// System.Int32 TimerNode::repeat
	int32_t ___repeat_3;
	// System.Single TimerNode::passedTime
	float ___passedTime_4;
	// System.Boolean TimerNode::isRemoved
	bool ___isRemoved_5;
	// System.Int32 TimerNode::timerId
	int32_t ___timerId_6;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
};

// HallScene/<ShowStartObj>d__25
struct U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41  : public RuntimeObject
{
	// System.Int32 HallScene/<ShowStartObj>d__25::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object HallScene/<ShowStartObj>d__25::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
};

// LoadScene/<ShowStartObj>d__10
struct U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944  : public RuntimeObject
{
	// System.Int32 LoadScene/<ShowStartObj>d__10::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object LoadScene/<ShowStartObj>d__10::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// LoadScene LoadScene/<ShowStartObj>d__10::<>4__this
	LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* ___U3CU3E4__this_2;
};

// MusicMgr/<>c__DisplayClass11_0
struct U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1  : public RuntimeObject
{
	// System.String MusicMgr/<>c__DisplayClass11_0::clipName
	String_t* ___clipName_0;
};

// PoolMgr/<>c__DisplayClass2_0
struct U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF  : public RuntimeObject
{
	// System.String PoolMgr/<>c__DisplayClass2_0::name
	String_t* ___name_0;
	// UnityEngine.Events.UnityAction`1<UnityEngine.GameObject> PoolMgr/<>c__DisplayClass2_0::callBack
	UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* ___callBack_1;
};

// ResManage/<WWWLoad>d__3
struct U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C  : public RuntimeObject
{
	// System.Int32 ResManage/<WWWLoad>d__3::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object ResManage/<WWWLoad>d__3::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// System.String ResManage/<WWWLoad>d__3::url
	String_t* ___url_2;
	// System.Action`1<UnityEngine.WWW> ResManage/<WWWLoad>d__3::callback
	Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF* ___callback_3;
	// UnityEngine.WWW ResManage/<WWWLoad>d__3::<www>5__2
	WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* ___U3CwwwU3E5__2_4;
};

// ScenesMgr/<ReallyLoadSceneAsyn>d__2
struct U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A  : public RuntimeObject
{
	// System.Int32 ScenesMgr/<ReallyLoadSceneAsyn>d__2::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object ScenesMgr/<ReallyLoadSceneAsyn>d__2::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// System.String ScenesMgr/<ReallyLoadSceneAsyn>d__2::name
	String_t* ___name_2;
	// UnityEngine.Events.UnityAction ScenesMgr/<ReallyLoadSceneAsyn>d__2::fun
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___fun_3;
	// UnityEngine.AsyncOperation ScenesMgr/<ReallyLoadSceneAsyn>d__2::<ao>5__2
	AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* ___U3CaoU3E5__2_4;
};

// Tools/<>c
struct U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290  : public RuntimeObject
{
};

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>
struct Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_dictionary
	Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_version
	int32_t ____version_2;
	// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_currentValue
	RuntimeObject* ____currentValue_3;
};

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>
struct Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_dictionary
	Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_version
	int32_t ____version_2;
	// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_currentValue
	TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* ____currentValue_3;
};

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>
struct KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	int32_t ___value_1;
};

// UnityEngine.AndroidJavaClass
struct AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03  : public AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// CardManager
struct CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203  : public BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936
{
	// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite> CardManager::cardSpriteDictionary
	Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* ___cardSpriteDictionary_1;
};

// UnityEngine.Color
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	// System.Single UnityEngine.Color::r
	float ___r_0;
	// System.Single UnityEngine.Color::g
	float ___g_1;
	// System.Single UnityEngine.Color::b
	float ___b_2;
	// System.Single UnityEngine.Color::a
	float ___a_3;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// EventCenter
struct EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170  : public BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19
{
	// System.Collections.Generic.Dictionary`2<System.String,IEventInfo> EventCenter::eventDic
	Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* ___eventDic_1;
};

// EventDispatcher
struct EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB  : public BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2
{
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate> EventDispatcher::listeners
	Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* ___listeners_1;
};

// GameData
struct GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6  : public BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1
{
	// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.Sprite> GameData::pokers
	Dictionary_2_tD001156821253ED04A22112577C96EFE869F40F0* ___pokers_1;
	// System.Boolean GameData::boolPlay
	bool ___boolPlay_2;
	// System.Boolean GameData::boolClick
	bool ___boolClick_3;
	// System.Int32 GameData::currentScore
	int32_t ___currentScore_4;
	// System.Single GameData::gameTimer
	float ___gameTimer_5;
	// System.Boolean GameData::boolFail
	bool ___boolFail_6;
	// System.String GameData::AndroidMessage
	String_t* ___AndroidMessage_7;
};

// InputMgr
struct InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C  : public BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E
{
	// System.Boolean InputMgr::isStart
	bool ___isStart_1;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// MonoMgr
struct MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47  : public BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161
{
	// MonoController MonoMgr::controller
	MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* ___controller_1;
};

// MusicMgr
struct MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB  : public BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863
{
	// System.String MusicMgr::soundUrl
	String_t* ___soundUrl_1;
	// System.Collections.Generic.List`1<UnityEngine.AudioClip> MusicMgr::audioClips
	List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* ___audioClips_2;
	// UnityEngine.AudioSource MusicMgr::bkMusic
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___bkMusic_3;
	// System.Single MusicMgr::bkValue
	float ___bkValue_4;
	// UnityEngine.GameObject MusicMgr::soundObj
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___soundObj_5;
	// System.Collections.Generic.List`1<UnityEngine.AudioSource> MusicMgr::soundList
	List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* ___soundList_6;
	// System.Single MusicMgr::soundValue
	float ___soundValue_7;
};

// PoolManage
struct PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266  : public BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93
{
	// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>> PoolManage::poolDic
	Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* ___poolDic_1;
};

// PoolMgr
struct PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F  : public BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330
{
	// System.Collections.Generic.Dictionary`2<System.String,PoolData> PoolMgr::poolDic
	Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* ___poolDic_1;
	// UnityEngine.GameObject PoolMgr::poolObj
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___poolObj_2;
};

// ResManage
struct ResManage_t5FAD4C5CBE0C758E708AF91991FD5E103F61E127  : public ResourcesLoadingMode_tBB229B38FF898346D20A767694266251D16C2048
{
};

// ResMgr
struct ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482  : public BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951
{
	// System.Collections.Hashtable ResMgr::m_res
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ___m_res_1;
};

// StuctsCom.SItemData
struct SItemData_tE2C9EC12BC0F35CE3660793381B7CE73D83165DD 
{
	// System.Int32 StuctsCom.SItemData::index
	int32_t ___index_0;
	// System.Int32 StuctsCom.SItemData::rand
	int32_t ___rand_1;
	// System.Int32 StuctsCom.SItemData::randDif
	int32_t ___randDif_2;
};

// StuctsCom.SPlayerData
struct SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6 
{
	// System.String StuctsCom.SPlayerData::name
	String_t* ___name_0;
	// System.Int32 StuctsCom.SPlayerData::playerScore
	int32_t ___playerScore_1;
};
// Native definition for P/Invoke marshalling of StuctsCom.SPlayerData
struct SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_pinvoke
{
	char* ___name_0;
	int32_t ___playerScore_1;
};
// Native definition for COM marshalling of StuctsCom.SPlayerData
struct SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_com
{
	Il2CppChar* ___name_0;
	int32_t ___playerScore_1;
};

// ScenesMgr
struct ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F  : public BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3
{
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// TextureMgr
struct TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901  : public BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF
{
	// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]> TextureMgr::m_pAtlasDic
	Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* ___m_pAtlasDic_1;
};

// TimerMgr
struct TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A  : public BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7
{
	// System.Collections.Generic.Dictionary`2<System.Int32,TimerNode> TimerMgr::timers
	Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* ___timers_1;
	// System.Collections.Generic.List`1<TimerNode> TimerMgr::removeTimers
	List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* ___removeTimers_2;
	// System.Collections.Generic.List`1<TimerNode> TimerMgr::newAddTimers
	List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* ___newAddTimers_3;
	// System.Int32 TimerMgr::autoIncId
	int32_t ___autoIncId_4;
};

// Tools
struct Tools_t3DF42EB905CE903A075617859FA36803BEC507C4  : public BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF
{
};

// UIManager
struct UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3  : public BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B
{
	// System.Collections.Generic.Dictionary`2<System.String,BasePanel> UIManager::panelDic
	Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* ___panelDic_1;
	// UnityEngine.Transform UIManager::bot
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___bot_2;
	// UnityEngine.Transform UIManager::mid
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___mid_3;
	// UnityEngine.Transform UIManager::top
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___top_4;
	// UnityEngine.RectTransform UIManager::canvas
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___canvas_5;
};

// UnityEngine.Vector4
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	// System.Single UnityEngine.Vector4::x
	float ___x_1;
	// System.Single UnityEngine.Vector4::y
	float ___y_2;
	// System.Single UnityEngine.Vector4::z
	float ___z_3;
	// System.Single UnityEngine.Vector4::w
	float ___w_4;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// UnityEngine.WWW
struct WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB  : public CustomYieldInstruction_t6B81A50D5D210C1ACAAE247FB53B65CDFFEB7617
{
	// UnityEngine.Networking.UnityWebRequest UnityEngine.WWW::_uwr
	UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* ____uwr_0;
};

// UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.Single UnityEngine.WaitForSeconds::m_Seconds
	float ___m_Seconds_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	float ___m_Seconds_0;
};
// Native definition for COM marshalling of UnityEngine.WaitForSeconds
struct WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	float ___m_Seconds_0;
};

// UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182 
{
	// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::activeEventSystem
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	// System.Boolean UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::sendEvents
	bool ___sendEvents_1;
	// System.Boolean UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::createPanelGameObjectsOnStart
	bool ___createPanelGameObjectsOnStart_2;
};
// Native definition for P/Invoke marshalling of UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182_marshaled_pinvoke
{
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	int32_t ___sendEvents_1;
	int32_t ___createPanelGameObjectsOnStart_2;
};
// Native definition for COM marshalling of UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182_marshaled_com
{
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	int32_t ___sendEvents_1;
	int32_t ___createPanelGameObjectsOnStart_2;
};

// UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.IntPtr UnityEngine.AsyncOperation::m_Ptr
	intptr_t ___m_Ptr_0;
	// System.Action`1<UnityEngine.AsyncOperation> UnityEngine.AsyncOperation::m_completeCallback
	Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB* ___m_completeCallback_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	Il2CppMethodPointer ___m_completeCallback_1;
};
// Native definition for COM marshalling of UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr_0;
	Il2CppMethodPointer ___m_completeCallback_1;
};

// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.IntPtr UnityEngine.Coroutine::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	Il2CppMethodPointer ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// UnityEngine.AudioClip
struct AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
	// UnityEngine.AudioClip/PCMReaderCallback UnityEngine.AudioClip::m_PCMReaderCallback
	PCMReaderCallback_t3396D9613664F0AFF65FB91018FD0F901CC16F1E* ___m_PCMReaderCallback_4;
	// UnityEngine.AudioClip/PCMSetPositionCallback UnityEngine.AudioClip::m_PCMSetPositionCallback
	PCMSetPositionCallback_t8D7135A2FB40647CAEC93F5254AD59E18DEB6072* ___m_PCMSetPositionCallback_5;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// System.Action`1<System.Object>
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87  : public MulticastDelegate_t
{
};

// System.Action`1<UnityEngine.WWW>
struct Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF  : public MulticastDelegate_t
{
};

// System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>>
struct Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E  : public MulticastDelegate_t
{
};

// System.Predicate`1<UnityEngine.AudioClip>
struct Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6  : public MulticastDelegate_t
{
};

// UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>
struct UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6  : public MulticastDelegate_t
{
};

// UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>
struct UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187  : public MulticastDelegate_t
{
};

// UnityEngine.Events.UnityAction`1<System.Object>
struct UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A  : public MulticastDelegate_t
{
};

// Act
struct Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE  : public MulticastDelegate_t
{
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7  : public MulticastDelegate_t
{
};

// TimerMgr/TimerHandler
struct TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23  : public MulticastDelegate_t
{
};

// UnityEngine.AudioBehaviour
struct AudioBehaviour_t2DC0BEF7B020C952F3D2DA5AAAC88501C7EEB941  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5  : public Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1
{
};

// AndroidJavaCShap
struct AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// GameData AndroidJavaCShap::gameData
	GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* ___gameData_4;
};

// UnityEngine.AudioSource
struct AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299  : public AudioBehaviour_t2DC0BEF7B020C952F3D2DA5AAAC88501C7EEB941
{
};

// BasePanel
struct BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>> BasePanel::controlDic
	Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26* ___controlDic_4;
};

// HallScene
struct HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text HallScene::text_score
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___text_score_4;
	// UnityEngine.UI.Text HallScene::text_time
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___text_time_5;
	// UnityEngine.GameObject HallScene::Pop_result
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___Pop_result_6;
	// UnityEngine.GameObject HallScene::btn_start
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___btn_start_7;
	// UnityEngine.Sprite[] HallScene::spriteArr
	SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* ___spriteArr_8;
	// UnityEngine.UI.Image[] HallScene::icon_pro
	ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* ___icon_pro_9;
	// UnityEngine.UI.Image[] HallScene::icon_li
	ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* ___icon_li_10;
	// TimerMgr HallScene::timer_game
	TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* ___timer_game_11;
	// GameData HallScene::gameData
	GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* ___gameData_12;
	// UnityEngine.AudioSource HallScene::audio
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___audio_13;
	// System.Single HallScene::gameTimer
	float ___gameTimer_14;
	// System.Int32 HallScene::TimerID_game
	int32_t ___TimerID_game_15;
	// System.Single HallScene::currentScore
	float ___currentScore_16;
	// System.Boolean HallScene::boolStartTime
	bool ___boolStartTime_17;
	// System.Boolean HallScene::isMoving
	bool ___isMoving_18;
	// System.Int32 HallScene::selecPro
	int32_t ___selecPro_19;
	// System.Int32 HallScene::selecLi
	int32_t ___selecLi_20;
	// System.Boolean HallScene::isCheckAndroidMessage
	bool ___isCheckAndroidMessage_21;
};

// LoadScene
struct LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.GameObject LoadScene::btn_obj
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___btn_obj_4;
	// UnityEngine.UI.Text LoadScene::text_load
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___text_load_5;
	// System.Boolean LoadScene::boolClickLogin
	bool ___boolClickLogin_6;
};

// MonoController
struct MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Events.UnityAction MonoController::updateEvent
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___updateEvent_4;
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseInputModule> UnityEngine.EventSystems.EventSystem::m_SystemInputModules
	List_1_tA5BDE435C735A082941CD33D212F97F4AE9FA55F* ___m_SystemInputModules_4;
	// UnityEngine.EventSystems.BaseInputModule UnityEngine.EventSystems.EventSystem::m_CurrentInputModule
	BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* ___m_CurrentInputModule_5;
	// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::m_FirstSelected
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_FirstSelected_7;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_sendNavigationEvents
	bool ___m_sendNavigationEvents_8;
	// System.Int32 UnityEngine.EventSystems.EventSystem::m_DragThreshold
	int32_t ___m_DragThreshold_9;
	// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::m_CurrentSelected
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_CurrentSelected_10;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_HasFocus
	bool ___m_HasFocus_11;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_SelectionGuard
	bool ___m_SelectionGuard_12;
	// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.EventSystem::m_DummyData
	BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___m_DummyData_13;
};

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.Material UnityEngine.UI.Graphic::m_Material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_Material_6;
	// UnityEngine.Color UnityEngine.UI.Graphic::m_Color
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_Color_7;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipLayoutUpdate
	bool ___m_SkipLayoutUpdate_8;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipMaterialUpdate
	bool ___m_SkipMaterialUpdate_9;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTarget
	bool ___m_RaycastTarget_10;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTargetCache
	bool ___m_RaycastTargetCache_11;
	// UnityEngine.Vector4 UnityEngine.UI.Graphic::m_RaycastPadding
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_RaycastPadding_12;
	// UnityEngine.RectTransform UnityEngine.UI.Graphic::m_RectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_RectTransform_13;
	// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::m_CanvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CanvasRenderer_14;
	// UnityEngine.Canvas UnityEngine.UI.Graphic::m_Canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_Canvas_15;
	// System.Boolean UnityEngine.UI.Graphic::m_VertsDirty
	bool ___m_VertsDirty_16;
	// System.Boolean UnityEngine.UI.Graphic::m_MaterialDirty
	bool ___m_MaterialDirty_17;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyLayoutCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyLayoutCallback_18;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyVertsCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyVertsCallback_19;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyMaterialCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyMaterialCallback_20;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::m_CachedMesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_CachedMesh_23;
	// UnityEngine.Vector2[] UnityEngine.UI.Graphic::m_CachedUvs
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___m_CachedUvs_24;
	// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween> UnityEngine.UI.Graphic::m_ColorTweenRunner
	TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4* ___m_ColorTweenRunner_25;
	// System.Boolean UnityEngine.UI.Graphic::<useLegacyMeshGeneration>k__BackingField
	bool ___U3CuseLegacyMeshGenerationU3Ek__BackingField_26;
};

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E  : public Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931
{
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculateStencil
	bool ___m_ShouldRecalculateStencil_27;
	// UnityEngine.Material UnityEngine.UI.MaskableGraphic::m_MaskMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_MaskMaterial_28;
	// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskableGraphic::m_ParentMask
	RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670* ___m_ParentMask_29;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_Maskable
	bool ___m_Maskable_30;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IsMaskingGraphic
	bool ___m_IsMaskingGraphic_31;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IncludeForMasking
	bool ___m_IncludeForMasking_32;
	// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::m_OnCullStateChanged
	CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8* ___m_OnCullStateChanged_33;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculate
	bool ___m_ShouldRecalculate_34;
	// System.Int32 UnityEngine.UI.MaskableGraphic::m_StencilValue
	int32_t ___m_StencilValue_35;
	// UnityEngine.Vector3[] UnityEngine.UI.MaskableGraphic::m_Corners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_Corners_36;
};

// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.Sprite UnityEngine.UI.Image::m_Sprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_Sprite_38;
	// UnityEngine.Sprite UnityEngine.UI.Image::m_OverrideSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_OverrideSprite_39;
	// UnityEngine.UI.Image/Type UnityEngine.UI.Image::m_Type
	int32_t ___m_Type_40;
	// System.Boolean UnityEngine.UI.Image::m_PreserveAspect
	bool ___m_PreserveAspect_41;
	// System.Boolean UnityEngine.UI.Image::m_FillCenter
	bool ___m_FillCenter_42;
	// UnityEngine.UI.Image/FillMethod UnityEngine.UI.Image::m_FillMethod
	int32_t ___m_FillMethod_43;
	// System.Single UnityEngine.UI.Image::m_FillAmount
	float ___m_FillAmount_44;
	// System.Boolean UnityEngine.UI.Image::m_FillClockwise
	bool ___m_FillClockwise_45;
	// System.Int32 UnityEngine.UI.Image::m_FillOrigin
	int32_t ___m_FillOrigin_46;
	// System.Single UnityEngine.UI.Image::m_AlphaHitTestMinimumThreshold
	float ___m_AlphaHitTestMinimumThreshold_47;
	// System.Boolean UnityEngine.UI.Image::m_Tracked
	bool ___m_Tracked_48;
	// System.Boolean UnityEngine.UI.Image::m_UseSpriteMesh
	bool ___m_UseSpriteMesh_49;
	// System.Single UnityEngine.UI.Image::m_PixelsPerUnitMultiplier
	float ___m_PixelsPerUnitMultiplier_50;
	// System.Single UnityEngine.UI.Image::m_CachedReferencePixelsPerUnit
	float ___m_CachedReferencePixelsPerUnit_51;
};

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.UI.FontData UnityEngine.UI.Text::m_FontData
	FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224* ___m_FontData_37;
	// System.String UnityEngine.UI.Text::m_Text
	String_t* ___m_Text_38;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCache
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCache_39;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCacheForLayout
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCacheForLayout_40;
	// System.Boolean UnityEngine.UI.Text::m_DisableFontTextureRebuiltCallback
	bool ___m_DisableFontTextureRebuiltCallback_42;
	// UnityEngine.UIVertex[] UnityEngine.UI.Text::m_TempVerts
	UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F* ___m_TempVerts_43;
};

// <Module>

// <Module>

// BaseManager`1<CardManager>
struct BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936_StaticFields
{
	// T BaseManager`1::instance
	CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203* ___instance_0;
};

// BaseManager`1<CardManager>

// BaseManager`1<EventCenter>
struct BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19_StaticFields
{
	// T BaseManager`1::instance
	EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* ___instance_0;
};

// BaseManager`1<EventCenter>

// BaseManager`1<EventDispatcher>
struct BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2_StaticFields
{
	// T BaseManager`1::instance
	EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* ___instance_0;
};

// BaseManager`1<EventDispatcher>

// BaseManager`1<GameData>
struct BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1_StaticFields
{
	// T BaseManager`1::instance
	GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* ___instance_0;
};

// BaseManager`1<GameData>

// BaseManager`1<InputMgr>
struct BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E_StaticFields
{
	// T BaseManager`1::instance
	InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* ___instance_0;
};

// BaseManager`1<InputMgr>

// BaseManager`1<MonoMgr>
struct BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161_StaticFields
{
	// T BaseManager`1::instance
	MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* ___instance_0;
};

// BaseManager`1<MonoMgr>

// BaseManager`1<MusicMgr>
struct BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863_StaticFields
{
	// T BaseManager`1::instance
	MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* ___instance_0;
};

// BaseManager`1<MusicMgr>

// BaseManager`1<PoolManage>
struct BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93_StaticFields
{
	// T BaseManager`1::instance
	PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266* ___instance_0;
};

// BaseManager`1<PoolManage>

// BaseManager`1<PoolMgr>
struct BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330_StaticFields
{
	// T BaseManager`1::instance
	PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F* ___instance_0;
};

// BaseManager`1<PoolMgr>

// BaseManager`1<ResMgr>
struct BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951_StaticFields
{
	// T BaseManager`1::instance
	ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* ___instance_0;
};

// BaseManager`1<ResMgr>

// BaseManager`1<ScenesMgr>
struct BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3_StaticFields
{
	// T BaseManager`1::instance
	ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* ___instance_0;
};

// BaseManager`1<ScenesMgr>

// BaseManager`1<TextureMgr>
struct BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF_StaticFields
{
	// T BaseManager`1::instance
	TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* ___instance_0;
};

// BaseManager`1<TextureMgr>

// BaseManager`1<TimerMgr>
struct BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7_StaticFields
{
	// T BaseManager`1::instance
	TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* ___instance_0;
};

// BaseManager`1<TimerMgr>

// BaseManager`1<Tools>
struct BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF_StaticFields
{
	// T BaseManager`1::instance
	Tools_t3DF42EB905CE903A075617859FA36803BEC507C4* ___instance_0;
};

// BaseManager`1<Tools>

// BaseManager`1<UIManager>
struct BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B_StaticFields
{
	// T BaseManager`1::instance
	UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3* ___instance_0;
};

// BaseManager`1<UIManager>

// System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>

// System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>

// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>

// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>

// System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>

// System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>

// System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>

// System.Collections.Generic.Dictionary`2<System.String,BasePanel>

// System.Collections.Generic.Dictionary`2<System.String,BasePanel>

// System.Collections.Generic.Dictionary`2<System.String,IEventInfo>

// System.Collections.Generic.Dictionary`2<System.String,IEventInfo>

// System.Collections.Generic.Dictionary`2<System.String,PoolData>

// System.Collections.Generic.Dictionary`2<System.String,PoolData>

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>

// System.EmptyArray`1<System.Object>
struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields
{
	// T[] System.EmptyArray`1::Value
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___Value_0;
};

// System.EmptyArray`1<System.Object>

// System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>
struct List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	IList_1U5BU5D_t80E946F93A165B207DCC681025281F722B753D2A* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>

// System.Collections.Generic.List`1<UnityEngine.AudioClip>
struct List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.AudioClip>

// System.Collections.Generic.List`1<UnityEngine.AudioSource>
struct List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	AudioSourceU5BU5D_tBBF6E920E0DC80D53D4BB2A8D4C80D244EF170B2* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.AudioSource>

// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	GameObjectU5BU5D_tFF67550DFCE87096D7A3734EA15B75896B2722CF* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.GameObject>

// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Int32>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.Collections.Generic.List`1<TimerNode>
struct List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	TimerNodeU5BU5D_t87E8231726A789A53902D248822EF9E7F4A6DF2D* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<TimerNode>

// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,TimerNode>

// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,TimerNode>

// UnityEngine.AndroidJavaObject
struct AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0_StaticFields
{
	// System.Boolean UnityEngine.AndroidJavaObject::enableDebugPrints
	bool ___enableDebugPrints_0;
};

// UnityEngine.AndroidJavaObject

// EventInfo

// EventInfo

// System.Collections.Hashtable
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_StaticFields
{
	// System.Runtime.CompilerServices.ConditionalWeakTable`2<System.Object,System.Runtime.Serialization.SerializationInfo> System.Collections.Hashtable::s_serializationInfoTable
	ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* ___s_serializationInfoTable_21;
};

// System.Collections.Hashtable

// PoolData

// PoolData

// System.Random
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_StaticFields
{
	// System.Random System.Random::s_globalRandom
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* ___s_globalRandom_4;
};

// System.Random
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_ThreadStaticFields
{
	// System.Random System.Random::t_threadRandom
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* ___t_threadRandom_3;
};

// ResourcesLoadingMode

// ResourcesLoadingMode

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// TimerNode

// TimerNode

// HallScene/<ShowStartObj>d__25

// HallScene/<ShowStartObj>d__25

// LoadScene/<ShowStartObj>d__10

// LoadScene/<ShowStartObj>d__10

// MusicMgr/<>c__DisplayClass11_0

// MusicMgr/<>c__DisplayClass11_0

// PoolMgr/<>c__DisplayClass2_0

// PoolMgr/<>c__DisplayClass2_0

// ResManage/<WWWLoad>d__3

// ResManage/<WWWLoad>d__3

// ScenesMgr/<ReallyLoadSceneAsyn>d__2

// ScenesMgr/<ReallyLoadSceneAsyn>d__2

// Tools/<>c
struct U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields
{
	// Tools/<>c Tools/<>c::<>9
	U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* ___U3CU3E9_0;
	// System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>> Tools/<>c::<>9__2_0
	Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* ___U3CU3E9__2_0_1;
};

// Tools/<>c

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>

// UnityEngine.AndroidJavaClass

// UnityEngine.AndroidJavaClass

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// CardManager

// CardManager

// System.Double

// System.Double

// EventCenter

// EventCenter

// EventDispatcher
struct EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_StaticFields
{
	// EventDispatcher EventDispatcher::GameWorldEventDispatcher
	EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* ___GameWorldEventDispatcher_2;
};

// EventDispatcher

// GameData

// GameData

// InputMgr

// InputMgr

// System.Int32

// System.Int32

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// MonoMgr

// MonoMgr

// MusicMgr

// MusicMgr

// PoolManage

// PoolManage

// PoolMgr

// PoolMgr

// ResManage

// ResManage

// ResMgr

// ResMgr

// StuctsCom.SItemData

// StuctsCom.SItemData

// StuctsCom.SPlayerData

// StuctsCom.SPlayerData

// ScenesMgr

// ScenesMgr

// System.Single

// System.Single

// TextureMgr

// TextureMgr

// TimerMgr

// TimerMgr

// Tools

// Tools

// UIManager

// UIManager

// System.Void

// System.Void

// UnityEngine.WWW

// UnityEngine.WWW

// UnityEngine.WaitForSeconds

// UnityEngine.WaitForSeconds

// UnityEngine.AsyncOperation

// UnityEngine.AsyncOperation

// UnityEngine.Coroutine

// UnityEngine.Coroutine

// System.Delegate

// System.Delegate

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// UnityEngine.AudioClip

// UnityEngine.AudioClip

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// UnityEngine.Sprite

// UnityEngine.Sprite

// System.Action`1<System.Object>

// System.Action`1<System.Object>

// System.Action`1<UnityEngine.WWW>

// System.Action`1<UnityEngine.WWW>

// System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>>

// System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>>

// System.Predicate`1<UnityEngine.AudioClip>

// System.Predicate`1<UnityEngine.AudioClip>

// UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>

// UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>

// UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>

// UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>

// UnityEngine.Events.UnityAction`1<System.Object>

// UnityEngine.Events.UnityAction`1<System.Object>

// Act

// Act

// System.ArgumentException

// System.ArgumentException

// System.AsyncCallback

// System.AsyncCallback

// System.NotSupportedException

// System.NotSupportedException

// UnityEngine.Transform

// UnityEngine.Transform

// UnityEngine.Events.UnityAction

// UnityEngine.Events.UnityAction

// TimerMgr/TimerHandler

// TimerMgr/TimerHandler

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5_StaticFields
{
	// UnityEngine.RectTransform/ReapplyDrivenProperties UnityEngine.RectTransform::reapplyDrivenProperties
	ReapplyDrivenProperties_t3482EA130A01FF7EE2EEFE37F66A5215D08CFE24* ___reapplyDrivenProperties_4;
};

// UnityEngine.RectTransform

// AndroidJavaCShap

// AndroidJavaCShap

// UnityEngine.AudioSource

// UnityEngine.AudioSource

// BasePanel

// BasePanel

// HallScene

// HallScene

// LoadScene

// LoadScene

// MonoController

// MonoController

// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_StaticFields
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventSystem> UnityEngine.EventSystems.EventSystem::m_EventSystems
	List_1_tF2FE88545EFEC788CAAE6C74EC2F78E937FCCAC3* ___m_EventSystems_6;
	// System.Comparison`1<UnityEngine.EventSystems.RaycastResult> UnityEngine.EventSystems.EventSystem::s_RaycastComparer
	Comparison_1_t9FCAC8C8CE160A96C5AAD2DE1D353DCE8A2FEEFC* ___s_RaycastComparer_14;
	// UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig UnityEngine.EventSystems.EventSystem::s_UIToolkitOverride
	UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182 ___s_UIToolkitOverride_15;
};

// UnityEngine.EventSystems.EventSystem

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Graphic::s_DefaultUI
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultUI_4;
	// UnityEngine.Texture2D UnityEngine.UI.Graphic::s_WhiteTexture
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___s_WhiteTexture_5;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::s_Mesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___s_Mesh_21;
	// UnityEngine.UI.VertexHelper UnityEngine.UI.Graphic::s_VertexHelper
	VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE* ___s_VertexHelper_22;
};

// UnityEngine.UI.Graphic

// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Image::s_ETC1DefaultUI
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_ETC1DefaultUI_37;
	// UnityEngine.Vector2[] UnityEngine.UI.Image::s_VertScratch
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___s_VertScratch_52;
	// UnityEngine.Vector2[] UnityEngine.UI.Image::s_UVScratch
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___s_UVScratch_53;
	// UnityEngine.Vector3[] UnityEngine.UI.Image::s_Xy
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___s_Xy_54;
	// UnityEngine.Vector3[] UnityEngine.UI.Image::s_Uv
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___s_Uv_55;
	// System.Collections.Generic.List`1<UnityEngine.UI.Image> UnityEngine.UI.Image::m_TrackedTexturelessImages
	List_1_tE6BB71ABF15905EFA2BE92C38A2716547AEADB19* ___m_TrackedTexturelessImages_56;
	// System.Boolean UnityEngine.UI.Image::s_Initialized
	bool ___s_Initialized_57;
};

// UnityEngine.UI.Image

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Text::s_DefaultText
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultText_41;
};

// UnityEngine.UI.Text
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// UnityEngine.Sprite[]
struct SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B  : public RuntimeArray
{
	ALIGN_FIELD (8) Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* m_Items[1];

	inline Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// UnityEngine.AudioClip[]
struct AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31  : public RuntimeArray
{
	ALIGN_FIELD (8) AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* m_Items[1];

	inline AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// UnityEngine.Object[]
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A  : public RuntimeArray
{
	ALIGN_FIELD (8) Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* m_Items[1];

	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// UnityEngine.UI.Image[]
struct ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78  : public RuntimeArray
{
	ALIGN_FIELD (8) Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* m_Items[1];

	inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
// System.Int32[][]
struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E  : public RuntimeArray
{
	ALIGN_FIELD (8) Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* m_Items[1];

	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// System.Void BasePanel::FindChildrenControl<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.Resources::LoadAll<System.Object>(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Resources_LoadAll_TisRuntimeObject_m69B3BC41DB42071369375275587F5A5FF5040487_gshared (String_t* ___0_path, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ContainsKey(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Item(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// System.Void BaseManager`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared (BaseManager_1_t05610E014301ECCB96A1DB8F51E4D6C3A23EAD39* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_mE1EFF7C68491EE07D21EE9924475A559BF0A4773_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2888D71A14F2B8510102F24FEE90552E91B124C1_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// T BaseManager`1<System.Object>::Getinstance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared (const RuntimeMethod* method) ;
// System.Void EventCenter::EventTrigger<System.Int32Enum>(System.String,T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_EventTrigger_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_mFD4C48FB86B515AD811E0401B20C0335554BD61B_gshared (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, int32_t ___1_info, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T[] ResMgr::LoadAll<System.Object>(System.String,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ResMgr_LoadAll_TisRuntimeObject_mFC86A09AD6106F86758B7200D0CDA95CE8E9AFA0_gshared (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_resPath, bool ___1_cache, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<System.Object>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Object>::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::RemoveAt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Predicate`1<System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20_gshared (Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Object>::Find(System.Predicate`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_Find_m5E78A210541B0D844FE27B94F509313623BE33D3_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* ___0_match, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Events.UnityAction`1<System.Object>::Invoke(T0)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityAction_1_Invoke_m777839BF9CB9F96B081106B47202D06FB35326CA_gshared_inline (UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A* __this, RuntimeObject* ___0_arg0, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Object>::Contains(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4C9139C2A6B23E9343D3F87807B32C6E2CFE660D_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Object>::Remove(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m4DFA48F4CEB9169601E75FC28517C5C06EFA5AD7_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void UnityEngine.Events.UnityAction`1<System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityAction_1__ctor_m0C2FC6B483B474AE9596A43EBA7FF6E85503A92A_gshared (UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void ResMgr::LoadAsync<System.Object>(System.String,UnityEngine.Events.UnityAction`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResMgr_LoadAsync_TisRuntimeObject_m9DF06A0834369CB1497833584B7605BBB6A8ED5E_gshared (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_pathName, UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A* ___1_callback, const RuntimeMethod* method) ;
// T UnityEngine.Resources::Load<System.Object>(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Resources_Load_TisRuntimeObject_mD1AF6299B14F87ED1D1A6199A51480919F7C79D7_gshared (String_t* ___0_path, const RuntimeMethod* method) ;
// T UnityEngine.Object::Instantiate<System.Object>(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Object_Instantiate_TisRuntimeObject_m90A1E6C4C2B445D2E848DB75C772D1B95AAC046A_gshared (RuntimeObject* ___0_original, const RuntimeMethod* method) ;
// System.Void BaseManager`1<System.Object>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseManager_1_Dispose_m9CF03A8902BCD55BD5BB1D54BAC1A66EC0DBCEB2_gshared (BaseManager_1_t05610E014301ECCB96A1DB8F51E4D6C3A23EAD39* __this, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Object>::Invoke(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
// System.Void EventCenter::EventTrigger<System.Single>(System.String,T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520_gshared (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, float ___1_info, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Remove(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ContainsKey(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_mED5C451F158CDDD2B3F4B0720CD248DA9DB27B25_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Item(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Item_mC3FEA647E750C27367C990777D8890E0E712E514_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Clear()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Values()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t65BBB6F728D41FD4760F6D6C59CC030CF237785F* Dictionary_2_get_Values_mC5B06C3C3FA89D62D6035C5B4C5E64A08FCF4DB9_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D ValueCollection_GetEnumerator_mDC2BD0AFDA087B7E7C23A8077E612664DFA8A152_gshared (ValueCollection_t65BBB6F728D41FD4760F6D6C59CC030CF237785F* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_m0647C4F434347E47D544621901E49835DF51F22B_gshared (Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D* __this, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m1412A508E37D95E08FB60E8976FB75714BE934C1_gshared_inline (Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,System.Object>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mF45CB0E0D7475963B61017A024634F60CF48548A_gshared (Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Remove(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// T ResMgr::Load<System.Object>(System.String,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ResMgr_Load_TisRuntimeObject_mB7903848B57975F5FFC5476489E02FF3D26AFCB1_gshared (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_resPath, bool ___1_cache, const RuntimeMethod* method) ;
// T[] System.Array::Empty<System.Object>()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline (const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Int32>::Contains(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<System.Int32>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Int32>::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F_gshared (Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.CollectionExtensions::TryAdd<System.Int32,System.Int32>(System.Collections.Generic.IDictionary`2<TKey,TValue>,TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_gshared (RuntimeObject* ___0_dictionary, int32_t ___1_key, int32_t ___2_value, const RuntimeMethod* method) ;
// TKey System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>::get_Key()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_gshared_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>::get_Value()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_gshared_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method) ;
// System.Void System.Comparison`1<System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Comparison_1__ctor_mC1E8799BBCE317B612875123C9C894BD470BFE6A_gshared (Comparison_1_t62E531E7B8260E2C6C2718C3BDB8CF8655139645* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Sort(System.Comparison`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mEB3B61CB86B1419919338B0668DC4E568C2FFF93_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, Comparison_1_t62E531E7B8260E2C6C2718C3BDB8CF8655139645* ___0_comparison, const RuntimeMethod* method) ;
// System.Collections.Generic.List`1<TSource> System.Linq.Enumerable::ToList<System.Int32>(System.Collections.Generic.IEnumerable`1<TSource>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::RemoveAt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method) ;

// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.Button>()
inline void BasePanel_FindChildrenControl_TisButton_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098_m029C39C826883D2524CA863001E667E87BE409A1 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.Image>()
inline void BasePanel_FindChildrenControl_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m47A1C2FF88A2A26CC43096D6216E399FCD8A6A7D (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.Text>()
inline void BasePanel_FindChildrenControl_TisText_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_m63245651BC205E8B7F07C02C05599F40069ACC98 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.Toggle>()
inline void BasePanel_FindChildrenControl_TisToggle_tBF13F3EBA485E06826FD8A38F4B4C1380DF21A1F_m43CBE6D9B457660C66048941ECE7D9D4567B9ADF (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.Slider>()
inline void BasePanel_FindChildrenControl_TisSlider_t87EA570E3D6556CABF57456C2F3873FFD86E652F_mA085184DD785D57BD63A352B6E5E204B60AABED2 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.ScrollRect>()
inline void BasePanel_FindChildrenControl_TisScrollRect_t17D2F2939CA8953110180DF53164CFC3DC88D70E_m9B6EADB8778BB07A420D8AEF2E0FB30962AD2BBF (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void BasePanel::FindChildrenControl<UnityEngine.UI.InputField>()
inline void BasePanel_FindChildrenControl_TisInputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_m343137C9C44061BD062868342886A83C5273ECAB (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method)
{
	((  void (*) (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D*, const RuntimeMethod*))BasePanel_FindChildrenControl_TisRuntimeObject_m1090116047E951D2B90E7BF4B9C841E5EADC8118_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.EventSystems.UIBehaviour>>::.ctor()
inline void Dictionary_2__ctor_m09BE4980B91235B1F22BBDFADADED0AFE80CEB53 (Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Combine(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00 (Delegate_t* ___0_a, Delegate_t* ___1_b, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Remove(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3 (Delegate_t* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_target, const RuntimeMethod* method) ;
// System.Void UnityEngine.Events.UnityAction::Invoke()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline (UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* __this, const RuntimeMethod* method) ;
// System.Void MonoController::add_updateEvent(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_add_updateEvent_m25BCD2AD7633E17C6F6BCD7EBD5A9CEB480C7727 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_value, const RuntimeMethod* method) ;
// System.Void MonoController::remove_updateEvent(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_remove_updateEvent_mD4AC81351A099CB5E2EE0D347785E5A5A1DBE2C7 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.Resources::LoadAll<UnityEngine.Sprite>(System.String)
inline SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* Resources_LoadAll_TisSprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_m5AB56F241D4637483AB93C9A1AADA0A304C8607E (String_t* ___0_path, const RuntimeMethod* method)
{
	return ((  SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* (*) (String_t*, const RuntimeMethod*))Resources_LoadAll_TisRuntimeObject_m69B3BC41DB42071369375275587F5A5FF5040487_gshared)(___0_path, method);
}
// System.String UnityEngine.Object::get_name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_mD460E52E10776520A9AD30A2BF1ED4E06F398727 (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* __this, String_t* ___0_key, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516*, String_t*, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99*, const RuntimeMethod*))Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m67CC65BB4A27FA582E357743809FD05E546E0C60 (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>::get_Item(TKey)
inline Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* Dictionary_2_get_Item_mC4807C8F26B84E5B332C4BD38978B9D8E3DF740D (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* (*) (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.String System.String::Concat(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogError(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>::.ctor()
inline void Dictionary_2__ctor_mDAFC0246415FCD20B4DFA892990A1AAA6F27C334 (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void BaseManager`1<CardManager>::.ctor()
inline void BaseManager_1__ctor_mB0C3F10038D85090EF52704CF110118CE22F9F91 (BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_tDEEB3263BC5B88911B13951322EF1365B2F69936*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,IEventInfo>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.String,IEventInfo>::get_Item(TKey)
inline RuntimeObject* Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8 (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.Void EventInfo::.ctor(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventInfo__ctor_m595BD0CA3BC92F8D72597A479D10DF5CB5CB0560 (EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_action, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,IEventInfo>::Add(TKey,TValue)
inline void Dictionary_2_Add_m02206C3B3DE104D0979A83B82914DD1E55287DFD (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* __this, String_t* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*, String_t*, RuntimeObject*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,IEventInfo>::Clear()
inline void Dictionary_2_Clear_m01EBB27E251F4438920D9DAB786F4A20E28EA82F (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*, const RuntimeMethod*))Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,IEventInfo>::.ctor()
inline void Dictionary_2__ctor_mE45CA150515955650A183C2827A3DA3A8770F80D (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void BaseManager`1<EventCenter>::.ctor()
inline void BaseManager_1__ctor_m447D12F4D58984A74CEC8FBA40A2134E96AC612A (BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t6D171BE0FFA63AC063A39F676915B8AB5B448F19*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>::.ctor()
inline void Dictionary_2__ctor_m5700B41402680D1EF55FD8A6B8ED41D348D9B83B (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*, const RuntimeMethod*))Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared)(__this, method);
}
// System.Void BaseManager`1<EventDispatcher>::.ctor()
inline void BaseManager_1__ctor_mEE6B30A7F62B93E4D5B5820A8D7FE5DE12CADA5D (BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t08B0EE16C1ACCD28C5DF3B4791799DD0E6D55CD2*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>::Clear()
inline void Dictionary_2_Clear_m8EC60FC45B7B894CCEF267E8D0A3DBA52A7897FF (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*, const RuntimeMethod*))Dictionary_2_Clear_mE1EFF7C68491EE07D21EE9924475A559BF0A4773_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* __this, int32_t ___0_key, Delegate_t** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*, int32_t, Delegate_t**, const RuntimeMethod*))Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>::Add(TKey,TValue)
inline void Dictionary_2_Add_mB7B8E9E63DD9C59E6683CFF7D32E372F86029A5B (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* __this, int32_t ___0_key, Delegate_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*, int32_t, Delegate_t*, const RuntimeMethod*))Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Delegate>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097 (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* __this, int32_t ___0_key, Delegate_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*, int32_t, Delegate_t*, const RuntimeMethod*))Dictionary_2_set_Item_m2888D71A14F2B8510102F24FEE90552E91B124C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void EventDispatcher::AddDelegate(System.Int32,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_AddDelegate_mEDFFFE8E44A2C641D8F30B6286B260660F973B59 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Delegate_t* ___1_listener, const RuntimeMethod* method) ;
// System.Void EventDispatcher::RemoveDelegate(System.Int32,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_RemoveDelegate_mFC216692915A8BF2F30CD72E9698E33660CFAD5B (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Delegate_t* ___1_listener, const RuntimeMethod* method) ;
// System.Void Act::Invoke()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_inline (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method) ;
// System.Void EventDispatcher::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher__ctor_mE5CA2506D8001F54FADEEC748B5254A3190B4C13 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, const RuntimeMethod* method) ;
// System.Void BaseManager`1<InputMgr>::.ctor()
inline void BaseManager_1__ctor_m8062140E42661EB2AB4A1030F79D18744A4B8588 (BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_tFE980B466DEE367E410426D41E8F377D818ACD4E*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// T BaseManager`1<MonoMgr>::Getinstance()
inline MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A (const RuntimeMethod* method)
{
	return ((  MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* (*) (const RuntimeMethod*))BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared)(method);
}
// System.Void UnityEngine.Events.UnityAction::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityAction__ctor_mC53E20D6B66E0D5688CD81B88DBB34F5A58B7131 (UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void MonoMgr::AddUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoMgr_AddUpdateListener_mA3B87871CCBFF2B79CB83D6A1B604DD3FA36FC6A (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Input::GetKeyDown(UnityEngine.KeyCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2 (int32_t ___0_key, const RuntimeMethod* method) ;
// T BaseManager`1<EventCenter>::Getinstance()
inline EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53 (const RuntimeMethod* method)
{
	return ((  EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* (*) (const RuntimeMethod*))BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared)(method);
}
// System.Void EventCenter::EventTrigger<UnityEngine.KeyCode>(System.String,T)
inline void EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283 (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, int32_t ___1_info, const RuntimeMethod* method)
{
	((  void (*) (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170*, String_t*, int32_t, const RuntimeMethod*))EventCenter_EventTrigger_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_mFD4C48FB86B515AD811E0401B20C0335554BD61B_gshared)(__this, ___0_name, ___1_info, method);
}
// System.Boolean UnityEngine.Input::GetKeyUp(UnityEngine.KeyCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetKeyUp_m9A962E395811A9901E7E05F267E198A533DBEF2F (int32_t ___0_key, const RuntimeMethod* method) ;
// System.Void InputMgr::CheckKeyCode(UnityEngine.KeyCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0 (InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// System.Void BaseManager`1<MonoMgr>::.ctor()
inline void BaseManager_1__ctor_m3B392CE03E1272ECCA3572C2636F6B8164800BF4 (BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t7A329BAD91F6270011ABD41ED210705699425161*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void UnityEngine.GameObject::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<MonoController>()
inline MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* GameObject_AddComponent_TisMonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8_mB2196B16A7FFE8997D15F0C33A4334876F1BA9E7 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared)(__this, method);
}
// System.Void MonoController::AddUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_AddUpdateListener_mEB7BC2F32C90688ABEBC26F6FC71133766B62FF4 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) ;
// System.Void MonoController::RemoveUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_RemoveUpdateListener_m8DFE3D0984F21C59AE0A9A7C1EBBA62CC1320672 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_mD754B72714F15210DDA429A096D853852FF437AB (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_m10C4B693B96175C42B0FD00911E072701C220DB4 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.AudioClip>::.ctor()
inline void List_1__ctor_m985F72633850464A3301F658B9CD510F7ADCDC33 (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.AudioSource>::.ctor()
inline void List_1__ctor_m1572AF991CD3CD21B43B0D6F699FE6296DEDF9E7 (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void BaseManager`1<MusicMgr>::.ctor()
inline void BaseManager_1__ctor_m90F17B40FD5672642AAA8231A17565250792C81D (BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t0AEB4CFBFE7C63F7EF9378999069730727853863*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// T UnityEngine.GameObject::AddComponent<UnityEngine.AudioSource>()
inline AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared)(__this, method);
}
// T BaseManager`1<ResMgr>::Getinstance()
inline ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC (const RuntimeMethod* method)
{
	return ((  ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* (*) (const RuntimeMethod*))BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared)(method);
}
// T[] ResMgr::LoadAll<UnityEngine.AudioClip>(System.String,System.Boolean)
inline AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* ResMgr_LoadAll_TisAudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20_m0E51BEBC9135361F746488BE347CCF40C71FE769 (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_resPath, bool ___1_cache, const RuntimeMethod* method)
{
	return ((  AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* (*) (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482*, String_t*, bool, const RuntimeMethod*))ResMgr_LoadAll_TisRuntimeObject_mFC86A09AD6106F86758B7200D0CDA95CE8E9AFA0_gshared)(__this, ___0_resPath, ___1_cache, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.AudioClip>::Add(T)
inline void List_1_Add_m51C49FD07D05048E52C4324E83FEC9BD2174F6B7_inline (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* __this, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F*, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Int32 System.Collections.Generic.List`1<UnityEngine.AudioSource>::get_Count()
inline int32_t List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_inline (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
// T System.Collections.Generic.List`1<UnityEngine.AudioSource>::get_Item(System.Int32)
inline AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6 (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
// System.Boolean UnityEngine.AudioSource::get_isPlaying()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AudioSource_get_isPlaying_mC203303F2F7146B2C056CB47B9391463FDF408FC (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Object::Destroy(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.AudioSource>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_m023E515689BBE45DA9EE94BE763578B854A74CF2 (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared)(__this, ___0_index, method);
}
// System.Void MusicMgr/<>c__DisplayClass11_0::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass11_0__ctor_mD006ED08E4FB895F2F9F231072C827E9EDB53041 (U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* __this, const RuntimeMethod* method) ;
// System.Void System.Predicate`1<UnityEngine.AudioClip>::.ctor(System.Object,System.IntPtr)
inline void Predicate_1__ctor_m7223B14FD3962CE47DAC436DA2661ECD6F3DC93E (Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6*, RuntimeObject*, intptr_t, const RuntimeMethod*))Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20_gshared)(__this, ___0_object, ___1_method, method);
}
// T System.Collections.Generic.List`1<UnityEngine.AudioClip>::Find(System.Predicate`1<T>)
inline AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* List_1_Find_m7D74D30D22001969B022341FCB9E7BB633C9638F (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* __this, Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6* ___0_match, const RuntimeMethod* method)
{
	return ((  AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* (*) (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F*, Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6*, const RuntimeMethod*))List_1_Find_m5E78A210541B0D844FE27B94F509313623BE33D3_gshared)(__this, ___0_match, method);
}
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m7D0340DE160786E6EFA8DABD39EC3B694DA30AAD (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Object::set_name(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.AudioClip MusicMgr::GetAudioClipByName(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* MusicMgr_GetAudioClipByName_m3477B862E0DC8B63AACAB1E903381832F4ED5C6F (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, String_t* ___0_clipName, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Implicit(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_exists, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::set_clip(UnityEngine.AudioClip)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_set_clip_mFF441895E274286C88D9C75ED5CA1B1B39528D70 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::set_loop(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_set_loop_m834A590939D8456008C0F897FD80B0ECFFB7FE56 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::set_volume(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::Play()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::Pause()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_Pause_m2C2A09359E8AA924FEADECC1AFEA519B3C915B26 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.AudioSource::Stop()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AudioSource_Stop_m318F17F17A147C77FF6E0A5A7A6BE057DB90F537 (AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<UnityEngine.AudioSource>()
inline AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* GameObject_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m4F30DAB8E5B57E8DB6BD8C0C3BB11CCB57690C4A (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.AudioSource>::Add(T)
inline void List_1_Add_m854AB1F4912F4A70C478FAE8E282C8F6CE880550_inline (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>::Invoke(T0)
inline void UnityAction_1_Invoke_m93F914E6E8E50FAAD27933A3291E1AB6E6CD144D_inline (UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6* __this, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___0_arg0, const RuntimeMethod* method)
{
	((  void (*) (UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6*, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299*, const RuntimeMethod*))UnityAction_1_Invoke_m777839BF9CB9F96B081106B47202D06FB35326CA_gshared_inline)(__this, ___0_arg0, method);
}
// System.Boolean System.Collections.Generic.List`1<UnityEngine.AudioSource>::Contains(T)
inline bool List_1_Contains_m85C62F7184BE9A0919BFBB82DE91D6C4AB143BD6 (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299*, const RuntimeMethod*))List_1_Contains_m4C9139C2A6B23E9343D3F87807B32C6E2CFE660D_gshared)(__this, ___0_item, method);
}
// System.Boolean System.Collections.Generic.List`1<UnityEngine.AudioSource>::Remove(T)
inline bool List_1_Remove_m7F54CE1C95A107E8F4A696104788E78107528DDB (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* __this, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299*, const RuntimeMethod*))List_1_Remove_m4DFA48F4CEB9169601E75FC28517C5C06EFA5AD7_gshared)(__this, ___0_item, method);
}
// System.Boolean System.String::op_Equality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.GameObject::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_parent(UnityEngine.Transform)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_parent_m9BD5E563B539DD5BEC342736B03F97B38A243234 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::.ctor()
inline void List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void PoolData::PushObj(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolData_PushObj_m89E38D986DAD45CC4A70CF6C9546A1FE175FA60B (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_obj, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::SetActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::Add(T)
inline void List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void UnityEngine.Transform::SetParent(UnityEngine.Transform)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_SetParent_m6677538B60246D958DD91F931C50F969CCBB5250 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_p, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<UnityEngine.GameObject>::get_Item(System.Int32)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979 (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.GameObject>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260 (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared)(__this, ___0_index, method);
}
// System.Void PoolMgr/<>c__DisplayClass2_0::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass2_0__ctor_mE4FBE720A9EF4E79A8E175641CA71D2041C29E83 (U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,PoolData>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366 (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.String,PoolData>::get_Item(TKey)
inline PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442 (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* (*) (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.Int32 System.Collections.Generic.List`1<UnityEngine.GameObject>::get_Count()
inline int32_t List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_inline (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
// UnityEngine.GameObject PoolData::GetObj()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PoolData_GetObj_m760D25B289FD5BF400C34811EF17B6D93620465F (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>::Invoke(T0)
inline void UnityAction_1_Invoke_mC0B03E675E5A61F6BDCA0F469FA5CCF9C4E52159_inline (UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_arg0, const RuntimeMethod* method)
{
	((  void (*) (UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187*, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))UnityAction_1_Invoke_m777839BF9CB9F96B081106B47202D06FB35326CA_gshared_inline)(__this, ___0_arg0, method);
}
// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>::.ctor(System.Object,System.IntPtr)
inline void UnityAction_1__ctor_m4AAE7BBE595D82E15A5A774EEB588EA82A63C16E (UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187*, RuntimeObject*, intptr_t, const RuntimeMethod*))UnityAction_1__ctor_m0C2FC6B483B474AE9596A43EBA7FF6E85503A92A_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void ResMgr::LoadAsync<UnityEngine.GameObject>(System.String,UnityEngine.Events.UnityAction`1<T>)
inline void ResMgr_LoadAsync_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_mAAEEB26879FEB6A44035D9B29A86CDEC4013F84F (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_pathName, UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* ___1_callback, const RuntimeMethod* method)
{
	((  void (*) (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482*, String_t*, UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187*, const RuntimeMethod*))ResMgr_LoadAsync_TisRuntimeObject_m9DF06A0834369CB1497833584B7605BBB6A8ED5E_gshared)(__this, ___0_pathName, ___1_callback, method);
}
// System.Void PoolData::.ctor(UnityEngine.GameObject,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolData__ctor_mBE70CAE9EBCD5C946D34BEDC59DEC5FDC74D8034 (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_obj, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___1_poolObj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,PoolData>::Add(TKey,TValue)
inline void Dictionary_2_Add_mC87FA1BC7656A1A1B43AEC922DB326EE287988C9 (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* __this, String_t* ___0_key, PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*, String_t*, PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,PoolData>::Clear()
inline void Dictionary_2_Clear_m08917F7954D626ED30A494E9127F69C3002BE29A (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*, const RuntimeMethod*))Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,PoolData>::.ctor()
inline void Dictionary_2__ctor_mE4874F66ADA7FCBE7FB1BEDBA767DCEC3CCDF624 (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void BaseManager`1<PoolMgr>::.ctor()
inline void BaseManager_1__ctor_mA6B8F030965B62068872EE479BB3B09A3732A1E1 (BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t92174B16DEECE4AB5D1E7E13A1EF236E1C94F330*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>::get_Item(TKey)
inline List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* (*) (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// T UnityEngine.Resources::Load<UnityEngine.GameObject>(System.String)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Resources_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m496A3B1B60A28F5E0397043974B848C9157B625A (String_t* ___0_path, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (String_t*, const RuntimeMethod*))Resources_Load_TisRuntimeObject_mD1AF6299B14F87ED1D1A6199A51480919F7C79D7_gshared)(___0_path, method);
}
// T UnityEngine.Object::Instantiate<UnityEngine.GameObject>(T)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m10D87C6E0708CA912BBB02555BF7D0FBC5D7A2B3 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_original, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))Object_Instantiate_TisRuntimeObject_m90A1E6C4C2B445D2E848DB75C772D1B95AAC046A_gshared)(___0_original, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>::Add(TKey,TValue)
inline void Dictionary_2_Add_m262241C63CA5FD4C4C40338008DD2097E94E6222 (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* __this, String_t* ___0_key, List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84*, String_t*, List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<UnityEngine.GameObject>>::.ctor()
inline void Dictionary_2__ctor_mC3BBDDAFE2FBCB7710787DE56899D4E6BCD9C0A2 (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void BaseManager`1<PoolManage>::.ctor()
inline void BaseManager_1__ctor_mF24449044241FBE79F9117BCEFA3220A9B495B53 (BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t53A31E52BA6B3BD78BDF8656BB13FB4F14E8CD93*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void System.Collections.Hashtable::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* __this, const RuntimeMethod* method) ;
// System.Void BaseManager`1<ResMgr>::Dispose()
inline void BaseManager_1_Dispose_mA0466D2F6A65CDCB41846E8C8A5AAF739E38CA53 (BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951*, const RuntimeMethod*))BaseManager_1_Dispose_m9CF03A8902BCD55BD5BB1D54BAC1A66EC0DBCEB2_gshared)(__this, method);
}
// UnityEngine.AsyncOperation UnityEngine.Resources::UnloadUnusedAssets()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* Resources_UnloadUnusedAssets_m4003CD3EBC3AC2738DE9F2960D5BC45818C1F12B (const RuntimeMethod* method) ;
// System.Void BaseManager`1<ResMgr>::.ctor()
inline void BaseManager_1__ctor_m12855CB17B210C30B34A51A5F46133DC89EC1143 (BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t8B55F27DF1E5A76634A7631EC594E5C01C7E0951*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void ResManage/<WWWLoad>d__3::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CWWWLoadU3Ed__3__ctor_m1ED9A98955F2F523E6A11F1AD9F1BFD6AD0B9C8D (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void ResourcesLoadingMode::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResourcesLoadingMode__ctor_mFBEFA8507463700AC45710EE43B394FCDFE40CBD (ResourcesLoadingMode_tBB229B38FF898346D20A767694266251D16C2048* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void UnityEngine.WWW::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WWW__ctor_m5D29D83E9EE0925ED8252347CE24EC236401503D (WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* __this, String_t* ___0_url, const RuntimeMethod* method) ;
// System.Void System.Action`1<UnityEngine.WWW>::Invoke(T)
inline void Action_1_Invoke_mD3170EC156395DBCCB2DC1491C5988F3CB2FEB5A_inline (Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF* __this, WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF*, WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB*, const RuntimeMethod*))Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline)(__this, ___0_obj, method);
}
// System.Void System.NotSupportedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.SceneManagement.SceneManager::LoadScene(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E (String_t* ___0_sceneName, const RuntimeMethod* method) ;
// System.Collections.IEnumerator ScenesMgr::ReallyLoadSceneAsyn(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ScenesMgr_ReallyLoadSceneAsyn_mCFA56D1928B38BC5EFA4C026F297400E231E7A26 (ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_fun, const RuntimeMethod* method) ;
// UnityEngine.Coroutine MonoMgr::StartCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoMgr_StartCoroutine_m1B651E11C49C987BA6649A89284AE7FBBF081F2B (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) ;
// System.Void ScenesMgr/<ReallyLoadSceneAsyn>d__2::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CReallyLoadSceneAsynU3Ed__2__ctor_m76E9A84E1DDFB502D080BB45D52E3C2C80FDDA55 (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void BaseManager`1<ScenesMgr>::.ctor()
inline void BaseManager_1__ctor_m281F94215DC637D51B8209FC887A679AB62DBF72 (BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_tB0BE7B81D59BE72FC7B488207F776BF1A1B5CFE3*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// UnityEngine.AsyncOperation UnityEngine.SceneManagement.SceneManager::LoadSceneAsync(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* SceneManager_LoadSceneAsync_m84D316B1993A4E69F9E8CDE30531687B701F9300 (String_t* ___0_sceneName, const RuntimeMethod* method) ;
// System.Single UnityEngine.AsyncOperation::get_progress()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AsyncOperation_get_progress_mF3B2837C1A5DDF3C2F7A3BA1E449DD4C71C632EE (AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* __this, const RuntimeMethod* method) ;
// System.Void EventCenter::EventTrigger<System.Single>(System.String,T)
inline void EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520 (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, float ___1_info, const RuntimeMethod* method)
{
	((  void (*) (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170*, String_t*, float, const RuntimeMethod*))EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520_gshared)(__this, ___0_name, ___1_info, method);
}
// System.Boolean UnityEngine.AsyncOperation::get_isDone()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AsyncOperation_get_isDone_m68A0682777E2132FC033182E9F50303566AA354D (AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>::.ctor()
inline void Dictionary_2__ctor_mFAF8880680AB14AC23BE7F389E98862841A59CE9 (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74 (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>::Remove(TKey)
inline bool Dictionary_2_Remove_m1F5269D68341155CEFF355916ED98C36FB157D29 (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*, String_t*, const RuntimeMethod*))Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared)(__this, ___0_key, method);
}
// UnityEngine.Object[] UnityEngine.Resources::LoadAll(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* Resources_LoadAll_m3C9742F2FA0ADB6F8C057527D0588F5BDCF8CF56 (String_t* ___0_path, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>::Add(TKey,TValue)
inline void Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2 (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* __this, String_t* ___0_key, ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*, String_t*, ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// UnityEngine.Sprite TextureMgr::FindSpriteFormBuffer(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* TextureMgr_FindSpriteFormBuffer_m1890DCADE0F513543E47712C4366A0FE8F92BB56 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, String_t* ___0__spriteAtlasPath, String_t* ___1__spriteName, const RuntimeMethod* method) ;
// UnityEngine.Sprite TextureMgr::SpriteFormAtlas(UnityEngine.Object[],System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* TextureMgr_SpriteFormAtlas_mB65341B2D4505ABF3F52ABE987CF39BA24F809EE (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* ___0__atlas, String_t* ___1__spriteName, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Object[]>::get_Item(TKey)
inline ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* Dictionary_2_get_Item_mBA8590162AAF64A9FEA05B610BCDCB7904D55587 (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* (*) (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.Void UnityEngine.Debug::LogWarning(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void BaseManager`1<TextureMgr>::.ctor()
inline void BaseManager_1__ctor_mDC5FD6061CABB05CC105C36E9311336DD2BDCF0C (BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_tE16E2B744CCCB21972DFAE46E8B70939CCCB47BF*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::.ctor()
inline void Dictionary_2__ctor_mA1D9EB14DD67356C94A0C1717D80F18979B839C0 (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, const RuntimeMethod*))Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<TimerNode>::.ctor()
inline void List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64 (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void TimerNode::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerNode__ctor_mBF40DD1358D6BD9044E38145D03FF7023C2EE7BF (TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TimerNode>::Add(T)
inline void List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_inline (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* __this, TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*, TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_m1711AF6E4992D16A259079D27B3B190A2E0641D3 (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, int32_t, const RuntimeMethod*))Dictionary_2_ContainsKey_mED5C451F158CDDD2B3F4B0720CD248DA9DB27B25_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::get_Item(TKey)
inline TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* Dictionary_2_get_Item_m779DD6A6BA1E9FA43761E654977AE8C9CC45FF34 (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, int32_t, const RuntimeMethod*))Dictionary_2_get_Item_mC3FEA647E750C27367C990777D8890E0E712E514_gshared)(__this, ___0_key, method);
}
// System.Single UnityEngine.Time::get_deltaTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865 (const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<TimerNode>::get_Item(System.Int32)
inline TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* (*) (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::Add(TKey,TValue)
inline void Dictionary_2_Add_m9AFDA112B11C0CD915081B9B2DF3B78C84CD82E8 (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, int32_t ___0_key, TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, int32_t, TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7*, const RuntimeMethod*))Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Int32 System.Collections.Generic.List`1<TimerNode>::get_Count()
inline int32_t List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_inline (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
// System.Void System.Collections.Generic.List`1<TimerNode>::Clear()
inline void List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_inline (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::get_Values()
inline ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97* Dictionary_2_get_Values_m88D0B7D51A606222E4BBAFF146B77772E5491B7E (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, const RuntimeMethod* method)
{
	return ((  ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97* (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, const RuntimeMethod*))Dictionary_2_get_Values_mC5B06C3C3FA89D62D6035C5B4C5E64A08FCF4DB9_gshared)(__this, method);
}
// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,TimerNode>::GetEnumerator()
inline Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934 ValueCollection_GetEnumerator_mA8242DA37C7181A80FCEEB7535CA464991FC2C17 (ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934 (*) (ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97*, const RuntimeMethod*))ValueCollection_GetEnumerator_mDC2BD0AFDA087B7E7C23A8077E612664DFA8A152_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>::Dispose()
inline void Enumerator_Dispose_mA4BD3457EF4189DB8017D964A865BF98CE30DEC9 (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934*, const RuntimeMethod*))Enumerator_Dispose_m0647C4F434347E47D544621901E49835DF51F22B_gshared)(__this, method);
}
// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>::get_Current()
inline TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* Enumerator_get_Current_m92C769426ADE52700E4F8E40760D6F8FAED469ED_inline (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934* __this, const RuntimeMethod* method)
{
	return ((  TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* (*) (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934*, const RuntimeMethod*))Enumerator_get_Current_m1412A508E37D95E08FB60E8976FB75714BE934C1_gshared_inline)(__this, method);
}
// System.Void TimerMgr/TimerHandler::Invoke()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_inline (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Int32,TimerNode>::MoveNext()
inline bool Enumerator_MoveNext_m8172A0F32B0FD2CB250B2F7E9B1B4ED285A0E4CF (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934*, const RuntimeMethod*))Enumerator_MoveNext_mF45CB0E0D7475963B61017A024634F60CF48548A_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,TimerNode>::Remove(TKey)
inline bool Dictionary_2_Remove_m37200A4980CCA1989CFE0A913D65F5B9D8E507D3 (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*, int32_t, const RuntimeMethod*))Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared)(__this, ___0_key, method);
}
// System.Void BaseManager`1<TimerMgr>::.ctor()
inline void BaseManager_1__ctor_m10373C1881893A2C205BE38BF428C64D736D3F88 (BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_tB3AC5B9820C7C0968806145FC9E29174DF1254D7*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,BasePanel>::.ctor()
inline void Dictionary_2__ctor_m8ADA5D11C145B740261CF875F392AF711FE1423C (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void BaseManager`1<UIManager>::.ctor()
inline void BaseManager_1__ctor_m77C93A4EE16FCB481F59FCF871382DFB8C142CAA (BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t004DB7606B3672AA72FF433D2DC4A115F7739F9B*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// T ResMgr::Load<UnityEngine.GameObject>(System.String,System.Boolean)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, String_t* ___0_resPath, bool ___1_cache, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482*, String_t*, bool, const RuntimeMethod*))ResMgr_Load_TisRuntimeObject_mB7903848B57975F5FFC5476489E02FF3D26AFCB1_gshared)(__this, ___0_resPath, ___1_cache, method);
}
// UnityEngine.Transform UnityEngine.Transform::Find(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Transform_Find_m3087032B0E1C5B96A2D2C27020BAEAE2DA08F932 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, String_t* ___0_n, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,BasePanel>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_mE7FD7A2EF471213473524B8051F0B27059B3E9F8 (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.String,BasePanel>::get_Item(TKey)
inline BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654 (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* (*) (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,BasePanel>::Remove(TKey)
inline bool Dictionary_2_Remove_mCE9DE052A13E9FF30C3200B08CE80100D8DB09C5 (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294*, String_t*, const RuntimeMethod*))Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared)(__this, ___0_key, method);
}
// System.Boolean System.String::IsNullOrEmpty(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
// System.Boolean System.String::Equals(System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_Equals_m7BDFC0B951005B9DC2BAED464AFE68FF7E9ACE5A (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
// System.Void UnityEngine.AndroidJavaClass::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaClass__ctor_mB5466169E1151B8CC44C8FED234D79984B431389 (AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* __this, String_t* ___0_className, const RuntimeMethod* method) ;
// T[] System.Array::Empty<System.Object>()
inline ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_inline (const RuntimeMethod* method)
{
	return ((  ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* (*) (const RuntimeMethod*))Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline)(method);
}
// System.Void UnityEngine.AndroidJavaObject::CallStatic(System.String,System.Object[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaObject_CallStatic_mB677DE04369EDD8E6DECAF2F233116EE1F06555C (AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0* __this, String_t* ___0_methodName, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
// System.Void BaseManager`1<GameData>::.ctor()
inline void BaseManager_1__ctor_mBCB1DDC744D6A952DA9059FAF2B78CD80D0B17A0 (BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t5E17750254F93A9923378B73E19AD7A07741A0C1*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void HallScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_InintView_m31696BDD1C9BEBC02E3238AEFB398D84F86C63FC (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.AudioSource>()
inline AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* Component_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m42DA4DEA19EB60D80CBED7413ADEB27FA033C77B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Void HallScene::UpdateTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateTime_m53A4F3F931334124691E572BE59782DE11A4A79E (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// System.Void HallScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateView_m0261A21525E07CABA321C768AB0D52BCE47FBF16 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// T BaseManager`1<TimerMgr>::Getinstance()
inline TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* BaseManager_1_Getinstance_m5F6E80E4D3876B809AAA9A749CE6A07FC7C6336D (const RuntimeMethod* method)
{
	return ((  TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* (*) (const RuntimeMethod*))BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared)(method);
}
// System.Void HallScene::UpdateDeltaTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateDeltaTime_mA9FF07331BA7577C57FC1242E8EE2E3B15339898 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// System.Void HallScene::PdResult()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_PdResult_m3D7443D35A2D2697C8E5707D877E5618075C1A59 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// System.Void GameData::AnalyseAjust()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameData_AnalyseAjust_m9F9CE5CD4B8AA2B44DAFF13778FD881E5CB9F8A5 (GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* __this, const RuntimeMethod* method) ;
// System.Void HallScene/<ShowStartObj>d__25::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__25__ctor_mD6FFBAD6B84D64550936A45E19D44759077C8C41 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.EventSystem::get_current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016 (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::get_currentSelectedGameObject()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline (EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* __this, const RuntimeMethod* method) ;
// System.Void HallScene::GameStart()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_GameStart_mE5436D22642A4AA8FC0BDA0C7FF60B89DB3FBE65 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// System.Void HallScene::Prohandel(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Prohandel_m2B1470028E31DCF32F6AE5F9C6517F25C9DBB85C (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_btnObj, const RuntimeMethod* method) ;
// System.Void HallScene::Lihandel(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Lihandel_m30E85664D6605DC13C0EF4D2D77DED93BE026A04 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, String_t* ___0_btnName, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<UnityEngine.UI.Image>()
inline Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
// UnityEngine.Sprite UnityEngine.UI.Image::get_sprite()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* Image_get_sprite_mB2AA377708722E100574F6F75BC102513BB3BCB1_inline (Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* __this, const RuntimeMethod* method) ;
// System.Int32 System.Int32::Parse(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0 (String_t* ___0_s, const RuntimeMethod* method) ;
// System.Void UnityEngine.UI.Image::set_sprite(UnityEngine.Sprite)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Image_set_sprite_mC0C248340BA27AAEE56855A3FAFA0D8CA12956DE (Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* __this, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___0_value, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Mathf::FloorToInt(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_FloorToInt_m2A39AE881CAEE6B6A4B3BFEF9CA1ED40625F5AB7_inline (float ___0_f, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
// System.String System.Single::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972 (float* __this, const RuntimeMethod* method) ;
// System.Void HallScene::UpdateRegPro()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateRegPro_m6F253F9BBE1C2D5C491346A5A8F503AC2AC34345 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::.ctor()
inline void List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8 (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, const RuntimeMethod*))List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_gshared)(__this, method);
}
// System.Int32 UnityEngine.Random::Range(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Random_Range_m6763D9767F033357F88B6637F048F4ACA4123B68 (int32_t ___0_minInclusive, int32_t ___1_maxExclusive, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Int32>::Contains(T)
inline bool List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B_gshared)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<System.Int32>::Add(T)
inline void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline)(__this, ___0_item, method);
}
// System.Int32 System.Collections.Generic.List`1<System.Int32>::get_Count()
inline int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, const RuntimeMethod*))List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline)(__this, method);
}
// T System.Collections.Generic.List`1<System.Int32>::get_Item(System.Int32)
inline int32_t List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_gshared)(__this, ___0_index, method);
}
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Inequality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.Void HallScene::UpdateScore()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateScore_m0B03238B4568E07C02C7FE2690F034C8BFA611BC (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) ;
// T BaseManager`1<GameData>::Getinstance()
inline GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4 (const RuntimeMethod* method)
{
	return ((  GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* (*) (const RuntimeMethod*))BaseManager_1_Getinstance_m7B90E6BBC9B67B0C671AA264B406CF0122C2A1E1_gshared)(method);
}
// System.Void UnityEngine.WaitForSeconds::.ctor(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* __this, float ___0_seconds, const RuntimeMethod* method) ;
// System.Void LoadScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_InintView_m848AFDAB275711BBC2032390AE7694E82045F7F4 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) ;
// System.Void LoadScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_UpdateView_mA94854795433FC09421CB8ACA0A8F3BC0FF5F8CD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.GameObject::get_activeSelf()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Collections.IEnumerator LoadScene::ShowStartObj()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* LoadScene_ShowStartObj_mCDB329E7C3CDAD36AE7088EE4DC798E3635B586F (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) ;
// System.Void LoadScene/<ShowStartObj>d__10::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__10__ctor_mF39C967B2CE23264C4C9FF4EE81CCA6A94271248 (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void LoadScene::LoadSceneHall()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_LoadSceneHall_m8954803260BB298171EDFB201E4ED1FCF4A8BA56 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) ;
// System.Void LoadScene::ChangeStatueLoad(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_ChangeStatueLoad_m4D36E62F61C5FE24229089A8B794A5EF01409AAD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, bool ___0_statues, const RuntimeMethod* method) ;
// System.Void AndroidJavaCShap::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_InintView_mFF65FB98D810F0709B283EC1A5E853FC6761DF08 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) ;
// System.Void AndroidJavaCShap::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_UpdateView_m92FE5422E3818C398AC5ADEF97246EF808329D26 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) ;
// System.Void System.Random::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor()
inline void Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F (Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180*, const RuntimeMethod*))Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.CollectionExtensions::TryAdd<System.Int32,System.Int32>(System.Collections.Generic.IDictionary`2<TKey,TValue>,TKey,TValue)
inline bool CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D (RuntimeObject* ___0_dictionary, int32_t ___1_key, int32_t ___2_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, int32_t, int32_t, const RuntimeMethod*))CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_gshared)(___0_dictionary, ___1_key, ___2_value, method);
}
// System.Void System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>::.ctor()
inline void List_1__ctor_m34392E0322B2071E67CE2DE1218585334AF12271 (List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// TKey System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>::get_Key()
inline int32_t KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189*, const RuntimeMethod*))KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_gshared_inline)(__this, method);
}
// TValue System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>::get_Value()
inline int32_t KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189*, const RuntimeMethod*))KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_gshared_inline)(__this, method);
}
// System.Void System.Comparison`1<System.Collections.Generic.IList`1<System.Int32>>::.ctor(System.Object,System.IntPtr)
inline void Comparison_1__ctor_m2968B906243D4C6719E52333B828FE2513B8D9E0 (Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E*, RuntimeObject*, intptr_t, const RuntimeMethod*))Comparison_1__ctor_mC1E8799BBCE317B612875123C9C894BD470BFE6A_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void System.Collections.Generic.List`1<System.Collections.Generic.IList`1<System.Int32>>::Sort(System.Comparison`1<T>)
inline void List_1_Sort_m0325E504A9F068571CDFAC2F69891902A1A7A263 (List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77* __this, Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* ___0_comparison, const RuntimeMethod* method)
{
	((  void (*) (List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77*, Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E*, const RuntimeMethod*))List_1_Sort_mEB3B61CB86B1419919338B0668DC4E568C2FFF93_gshared)(__this, ___0_comparison, method);
}
// System.Void System.ArgumentException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<System.Int32> System.Linq.Enumerable::Range(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Range_m4FB9BBBA09BEF5177C13506DB385CF4467C15FD8 (int32_t ___0_start, int32_t ___1_count, const RuntimeMethod* method) ;
// System.Collections.Generic.List`1<TSource> System.Linq.Enumerable::ToList<System.Int32>(System.Collections.Generic.IEnumerable`1<TSource>)
inline List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC_gshared)(___0_source, method);
}
// System.Void System.Collections.Generic.List`1<System.Int32>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004 (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_gshared)(__this, ___0_index, method);
}
// System.Void BaseManager`1<Tools>::.ctor()
inline void BaseManager_1__ctor_m783192CA846185C692F3A4D5EF88408EBD62E85E (BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseManager_1_t229B901EDCBB2F58AC519F19FEC2C6FFA54EAEFF*, const RuntimeMethod*))BaseManager_1__ctor_m807C6F866A4383B51CEDE490180FC67290F30FFE_gshared)(__this, method);
}
// System.Void Tools/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mCE0F9ED4FDCC9606AAE9870169BDCA3CB96A940A (U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* __this, const RuntimeMethod* method) ;
// System.Void System.Array::Clear(System.Array,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void BasePanel::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_Awake_mE340C9BF6812F82389C28FCBC2BEABCE50ACF798 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisButton_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098_m029C39C826883D2524CA863001E667E87BE409A1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m47A1C2FF88A2A26CC43096D6216E399FCD8A6A7D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisInputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_m343137C9C44061BD062868342886A83C5273ECAB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisScrollRect_t17D2F2939CA8953110180DF53164CFC3DC88D70E_m9B6EADB8778BB07A420D8AEF2E0FB30962AD2BBF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisSlider_t87EA570E3D6556CABF57456C2F3873FFD86E652F_mA085184DD785D57BD63A352B6E5E204B60AABED2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisText_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_m63245651BC205E8B7F07C02C05599F40069ACC98_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasePanel_FindChildrenControl_TisToggle_tBF13F3EBA485E06826FD8A38F4B4C1380DF21A1F_m43CBE6D9B457660C66048941ECE7D9D4567B9ADF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// FindChildrenControl<Button>();
		BasePanel_FindChildrenControl_TisButton_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098_m029C39C826883D2524CA863001E667E87BE409A1(__this, BasePanel_FindChildrenControl_TisButton_t6786514A57F7AFDEE5431112FEA0CAB24F5AE098_m029C39C826883D2524CA863001E667E87BE409A1_RuntimeMethod_var);
		// FindChildrenControl<Image>();
		BasePanel_FindChildrenControl_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m47A1C2FF88A2A26CC43096D6216E399FCD8A6A7D(__this, BasePanel_FindChildrenControl_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_m47A1C2FF88A2A26CC43096D6216E399FCD8A6A7D_RuntimeMethod_var);
		// FindChildrenControl<Text>();
		BasePanel_FindChildrenControl_TisText_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_m63245651BC205E8B7F07C02C05599F40069ACC98(__this, BasePanel_FindChildrenControl_TisText_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_m63245651BC205E8B7F07C02C05599F40069ACC98_RuntimeMethod_var);
		// FindChildrenControl<Toggle>();
		BasePanel_FindChildrenControl_TisToggle_tBF13F3EBA485E06826FD8A38F4B4C1380DF21A1F_m43CBE6D9B457660C66048941ECE7D9D4567B9ADF(__this, BasePanel_FindChildrenControl_TisToggle_tBF13F3EBA485E06826FD8A38F4B4C1380DF21A1F_m43CBE6D9B457660C66048941ECE7D9D4567B9ADF_RuntimeMethod_var);
		// FindChildrenControl<Slider>();
		BasePanel_FindChildrenControl_TisSlider_t87EA570E3D6556CABF57456C2F3873FFD86E652F_mA085184DD785D57BD63A352B6E5E204B60AABED2(__this, BasePanel_FindChildrenControl_TisSlider_t87EA570E3D6556CABF57456C2F3873FFD86E652F_mA085184DD785D57BD63A352B6E5E204B60AABED2_RuntimeMethod_var);
		// FindChildrenControl<ScrollRect>();
		BasePanel_FindChildrenControl_TisScrollRect_t17D2F2939CA8953110180DF53164CFC3DC88D70E_m9B6EADB8778BB07A420D8AEF2E0FB30962AD2BBF(__this, BasePanel_FindChildrenControl_TisScrollRect_t17D2F2939CA8953110180DF53164CFC3DC88D70E_m9B6EADB8778BB07A420D8AEF2E0FB30962AD2BBF_RuntimeMethod_var);
		// FindChildrenControl<InputField>();
		BasePanel_FindChildrenControl_TisInputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_m343137C9C44061BD062868342886A83C5273ECAB(__this, BasePanel_FindChildrenControl_TisInputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_m343137C9C44061BD062868342886A83C5273ECAB_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void BasePanel::ShowMe()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_ShowMe_m98BA45BE7F5086D596DE8AA73E0F3DCD1CF3BC4A (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void BasePanel::HideMe()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_HideMe_m55B55AAFAC1857F0534F914FB4860ED18300FF76 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void BasePanel::OnClick(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_OnClick_mD0D5F489D66238297DE7CFD26DDB48CC1598D5B1 (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, String_t* ___0_btnName, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void BasePanel::OnValueChanged(System.String,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel_OnValueChanged_mB28E033F6316AC781671A8D149C47E2B1BB46B5E (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, String_t* ___0_toggleName, bool ___1_value, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void BasePanel::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasePanel__ctor_m67B3D4AEB4D8C8D57E50D820C5CD114295CF472F (BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m09BE4980B91235B1F22BBDFADADED0AFE80CEB53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<string, List<UIBehaviour>> controlDic = new Dictionary<string, List<UIBehaviour>>();
		Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26* L_0 = (Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26*)il2cpp_codegen_object_new(Dictionary_2_t47EF3501577FC9C1F307D68972D088EFBF49FB26_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m09BE4980B91235B1F22BBDFADADED0AFE80CEB53(L_0, Dictionary_2__ctor_m09BE4980B91235B1F22BBDFADADED0AFE80CEB53_RuntimeMethod_var);
		__this->___controlDic_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___controlDic_4), (void*)L_0);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MonoController::add_updateEvent(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_add_updateEvent_m25BCD2AD7633E17C6F6BCD7EBD5A9CEB480C7727 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_0 = NULL;
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_1 = NULL;
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_2 = NULL;
	{
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = __this->___updateEvent_4;
		V_0 = L_0;
	}

IL_0007:
	{
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = V_0;
		V_1 = L_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_2 = V_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_4, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var));
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7** L_5 = (&__this->___updateEvent_4);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_6 = V_2;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_7 = V_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_8;
		L_8 = InterlockedCompareExchangeImpl<UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*>(L_5, L_6, L_7);
		V_0 = L_8;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_9 = V_0;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_10 = V_1;
		if ((!(((RuntimeObject*)(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)L_9) == ((RuntimeObject*)(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// System.Void MonoController::remove_updateEvent(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_remove_updateEvent_mD4AC81351A099CB5E2EE0D347785E5A5A1DBE2C7 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_0 = NULL;
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_1 = NULL;
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* V_2 = NULL;
	{
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = __this->___updateEvent_4;
		V_0 = L_0;
	}

IL_0007:
	{
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = V_0;
		V_1 = L_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_2 = V_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_4, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var));
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7** L_5 = (&__this->___updateEvent_4);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_6 = V_2;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_7 = V_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_8;
		L_8 = InterlockedCompareExchangeImpl<UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*>(L_5, L_6, L_7);
		V_0 = L_8;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_9 = V_0;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_10 = V_1;
		if ((!(((RuntimeObject*)(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)L_9) == ((RuntimeObject*)(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// System.Void MonoController::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_Start_m966107CF353ED54A4C134E0BA03225CBCF1D5640 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// DontDestroyOnLoad(this.gameObject);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0;
		L_0 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_0, NULL);
		// }
		return;
	}
}
// System.Void MonoController::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_Update_m21F8F3FD13454493D0C30F0BFEDE9EBD66670897 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, const RuntimeMethod* method) 
{
	{
		// if (updateEvent != null)
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = __this->___updateEvent_4;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		// updateEvent();
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = __this->___updateEvent_4;
		NullCheck(L_1);
		UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline(L_1, NULL);
	}

IL_0013:
	{
		// }
		return;
	}
}
// System.Void MonoController::AddUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_AddUpdateListener_mEB7BC2F32C90688ABEBC26F6FC71133766B62FF4 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) 
{
	{
		// updateEvent += fun;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = ___0_fun;
		MonoController_add_updateEvent_m25BCD2AD7633E17C6F6BCD7EBD5A9CEB480C7727(__this, L_0, NULL);
		// }
		return;
	}
}
// System.Void MonoController::RemoveUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController_RemoveUpdateListener_m8DFE3D0984F21C59AE0A9A7C1EBBA62CC1320672 (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) 
{
	{
		// updateEvent -= fun;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = ___0_fun;
		MonoController_remove_updateEvent_mD4AC81351A099CB5E2EE0D347785E5A5A1DBE2C7(__this, L_0, NULL);
		// }
		return;
	}
}
// System.Void MonoController::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoController__ctor_m3F2639C72FF7173F554220F2D95A0C76A7267CAF (MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ResourcesLoadingMode::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResourcesLoadingMode__ctor_mFBEFA8507463700AC45710EE43B394FCDFE40CBD (ResourcesLoadingMode_tBB229B38FF898346D20A767694266251D16C2048* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite> CardManager::LoadCardSprites(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* CardManager_LoadCardSprites_m0F91965A681AD2DF418ADF59468AF922BDDBF85C (CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203* __this, String_t* ___0_cardResourcesPath, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_mD460E52E10776520A9AD30A2BF1ED4E06F398727_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Resources_LoadAll_TisSprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_m5AB56F241D4637483AB93C9A1AADA0A304C8607E_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* V_0 = NULL;
	int32_t V_1 = 0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* V_2 = NULL;
	{
		// Sprite[] cardSprites = Resources.LoadAll<Sprite>(cardResourcesPath);
		String_t* L_0 = ___0_cardResourcesPath;
		SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* L_1;
		L_1 = Resources_LoadAll_TisSprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_m5AB56F241D4637483AB93C9A1AADA0A304C8607E(L_0, Resources_LoadAll_TisSprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_m5AB56F241D4637483AB93C9A1AADA0A304C8607E_RuntimeMethod_var);
		// foreach (Sprite sprite in cardSprites)
		V_0 = L_1;
		V_1 = 0;
		goto IL_0025;
	}

IL_000b:
	{
		// foreach (Sprite sprite in cardSprites)
		SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* L_2 = V_0;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_2 = L_5;
		// cardSpriteDictionary[sprite.name] = sprite;
		Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* L_6 = __this->___cardSpriteDictionary_1;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_7 = V_2;
		NullCheck(L_7);
		String_t* L_8;
		L_8 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_7, NULL);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_9 = V_2;
		NullCheck(L_6);
		Dictionary_2_set_Item_mD460E52E10776520A9AD30A2BF1ED4E06F398727(L_6, L_8, L_9, Dictionary_2_set_Item_mD460E52E10776520A9AD30A2BF1ED4E06F398727_RuntimeMethod_var);
		int32_t L_10 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0025:
	{
		// foreach (Sprite sprite in cardSprites)
		int32_t L_11 = V_1;
		SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* L_12 = V_0;
		NullCheck(L_12);
		if ((((int32_t)L_11) < ((int32_t)((int32_t)(((RuntimeArray*)L_12)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		// return cardSpriteDictionary;
		Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* L_13 = __this->___cardSpriteDictionary_1;
		return L_13;
	}
}
// UnityEngine.Sprite CardManager::GetCardSpriteByName(System.String,System.Collections.Generic.Dictionary`2<System.String,UnityEngine.Sprite>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* CardManager_GetCardSpriteByName_m4294757E651431B3F4575C916B12D541865C5FBC (CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203* __this, String_t* ___0_cardName, Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* ___1_cardSpriteDictionary, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m67CC65BB4A27FA582E357743809FD05E546E0C60_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mC4807C8F26B84E5B332C4BD38978B9D8E3DF740D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral17FC0954E2BA29F862AC82AAF54615D8CF0A5190);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD0B7C5B0A0F6BAC914AB8AF13D0CC0A273F0A51D);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (cardSpriteDictionary.ContainsKey(cardName))
		Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* L_0 = ___1_cardSpriteDictionary;
		String_t* L_1 = ___0_cardName;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m67CC65BB4A27FA582E357743809FD05E546E0C60(L_0, L_1, Dictionary_2_ContainsKey_m67CC65BB4A27FA582E357743809FD05E546E0C60_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0011;
		}
	}
	{
		// return cardSpriteDictionary[cardName];
		Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* L_3 = ___1_cardSpriteDictionary;
		String_t* L_4 = ___0_cardName;
		NullCheck(L_3);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_5;
		L_5 = Dictionary_2_get_Item_mC4807C8F26B84E5B332C4BD38978B9D8E3DF740D(L_3, L_4, Dictionary_2_get_Item_mC4807C8F26B84E5B332C4BD38978B9D8E3DF740D_RuntimeMethod_var);
		return L_5;
	}

IL_0011:
	{
		// Debug.LogError("Card sprite with name " + cardName + " not found.");
		String_t* L_6 = ___0_cardName;
		String_t* L_7;
		L_7 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteralD0B7C5B0A0F6BAC914AB8AF13D0CC0A273F0A51D, L_6, _stringLiteral17FC0954E2BA29F862AC82AAF54615D8CF0A5190, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_7, NULL);
		// return null;
		return (Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99*)NULL;
	}
}
// System.Void CardManager::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CardManager__ctor_mEAF4B560368DF13EA257B55B8074393E59B696CD (CardManager_t13D81CD3E2734FD058252E3965AAD55D6E87C203* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mB0C3F10038D85090EF52704CF110118CE22F9F91_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mDAFC0246415FCD20B4DFA892990A1AAA6F27C334_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<string, Sprite> cardSpriteDictionary = new Dictionary<string, Sprite>();
		Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516* L_0 = (Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516*)il2cpp_codegen_object_new(Dictionary_2_tC7B9BD0CA755DD1E643DB18A74765E15DC3D9516_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mDAFC0246415FCD20B4DFA892990A1AAA6F27C334(L_0, Dictionary_2__ctor_mDAFC0246415FCD20B4DFA892990A1AAA6F27C334_RuntimeMethod_var);
		__this->___cardSpriteDictionary_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___cardSpriteDictionary_1), (void*)L_0);
		BaseManager_1__ctor_mB0C3F10038D85090EF52704CF110118CE22F9F91(__this, BaseManager_1__ctor_mB0C3F10038D85090EF52704CF110118CE22F9F91_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void EventInfo::.ctor(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventInfo__ctor_m595BD0CA3BC92F8D72597A479D10DF5CB5CB0560 (EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_action, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public EventInfo(UnityAction action)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// actions += action;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_0 = __this->___actions_0;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = ___0_action;
		Delegate_t* L_2;
		L_2 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_0, L_1, NULL);
		__this->___actions_0 = ((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_2, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___actions_0), (void*)((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_2, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var)));
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void EventCenter::AddEventListener(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_AddEventListener_m3194B5D12672BA1AC22A01088C008777C0304F88 (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_action, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m02206C3B3DE104D0979A83B82914DD1E55287DFD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (eventDic.ContainsKey(name))
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_0 = __this->___eventDic_1;
		String_t* L_1 = ___0_name;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B(L_0, L_1, Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0036;
		}
	}
	{
		// (eventDic[name] as EventInfo).actions += action;
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_3 = __this->___eventDic_1;
		String_t* L_4 = ___0_name;
		NullCheck(L_3);
		RuntimeObject* L_5;
		L_5 = Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8(L_3, L_4, Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9* L_6 = ((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_5, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var));
		NullCheck(L_6);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_7 = L_6->___actions_0;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_8 = ___1_action;
		Delegate_t* L_9;
		L_9 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_7, L_8, NULL);
		NullCheck(L_6);
		L_6->___actions_0 = ((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_9, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&L_6->___actions_0), (void*)((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_9, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var)));
		return;
	}

IL_0036:
	{
		// eventDic.Add(name, new EventInfo(action));
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_10 = __this->___eventDic_1;
		String_t* L_11 = ___0_name;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_12 = ___1_action;
		EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9* L_13 = (EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)il2cpp_codegen_object_new(EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		EventInfo__ctor_m595BD0CA3BC92F8D72597A479D10DF5CB5CB0560(L_13, L_12, NULL);
		NullCheck(L_10);
		Dictionary_2_Add_m02206C3B3DE104D0979A83B82914DD1E55287DFD(L_10, L_11, L_13, Dictionary_2_Add_m02206C3B3DE104D0979A83B82914DD1E55287DFD_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void EventCenter::RemoveEventListener(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_RemoveEventListener_m7FBECE049EA78DA263FB0211926C31F08F01BAEA (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_action, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (eventDic.ContainsKey(name))
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_0 = __this->___eventDic_1;
		String_t* L_1 = ___0_name;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B(L_0, L_1, Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0035;
		}
	}
	{
		// (eventDic[name] as EventInfo).actions -= action;
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_3 = __this->___eventDic_1;
		String_t* L_4 = ___0_name;
		NullCheck(L_3);
		RuntimeObject* L_5;
		L_5 = Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8(L_3, L_4, Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9* L_6 = ((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_5, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var));
		NullCheck(L_6);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_7 = L_6->___actions_0;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_8 = ___1_action;
		Delegate_t* L_9;
		L_9 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_7, L_8, NULL);
		NullCheck(L_6);
		L_6->___actions_0 = ((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_9, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&L_6->___actions_0), (void*)((UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)CastclassSealed((RuntimeObject*)L_9, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var)));
	}

IL_0035:
	{
		// }
		return;
	}
}
// System.Void EventCenter::EventTrigger(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_EventTrigger_mE6769256B3928F5FF76A1B0F3497DE7DF7FC3167 (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (eventDic.ContainsKey(name))
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_0 = __this->___eventDic_1;
		String_t* L_1 = ___0_name;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B(L_0, L_1, Dictionary_2_ContainsKey_m7F02EC03444CF31249C7FA28825A5F516E878A1B_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0041;
		}
	}
	{
		// if ((eventDic[name] as EventInfo).actions != null)
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_3 = __this->___eventDic_1;
		String_t* L_4 = ___0_name;
		NullCheck(L_3);
		RuntimeObject* L_5;
		L_5 = Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8(L_3, L_4, Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		NullCheck(((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_5, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var)));
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_6 = ((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_5, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var))->___actions_0;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		// (eventDic[name] as EventInfo).actions.Invoke();
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_7 = __this->___eventDic_1;
		String_t* L_8 = ___0_name;
		NullCheck(L_7);
		RuntimeObject* L_9;
		L_9 = Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8(L_7, L_8, Dictionary_2_get_Item_m82EA628980464618FEF497AD71B8621DEA85E8F8_RuntimeMethod_var);
		NullCheck(((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_9, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var)));
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_10 = ((EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9*)IsInstClass((RuntimeObject*)L_9, EventInfo_t6C980BF842E5684A154EE94371B84D4B70968BD9_il2cpp_TypeInfo_var))->___actions_0;
		NullCheck(L_10);
		UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline(L_10, NULL);
	}

IL_0041:
	{
		// }
		return;
	}
}
// System.Void EventCenter::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter_Clear_mE5443BCE485D372F39B1A12CBAF81438F63ECE4C (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Clear_m01EBB27E251F4438920D9DAB786F4A20E28EA82F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// eventDic.Clear();
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_0 = __this->___eventDic_1;
		NullCheck(L_0);
		Dictionary_2_Clear_m01EBB27E251F4438920D9DAB786F4A20E28EA82F(L_0, Dictionary_2_Clear_m01EBB27E251F4438920D9DAB786F4A20E28EA82F_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void EventCenter::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCenter__ctor_mEEE40641698EDA3121FBDF9B5494CF9FD8FC0695 (EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m447D12F4D58984A74CEC8FBA40A2134E96AC612A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mE45CA150515955650A183C2827A3DA3A8770F80D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<string, IEventInfo> eventDic = new Dictionary<string, IEventInfo>();
		Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874* L_0 = (Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874*)il2cpp_codegen_object_new(Dictionary_2_t98BA8A54487C56D5695B289AC7F51F7D16ED9874_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mE45CA150515955650A183C2827A3DA3A8770F80D(L_0, Dictionary_2__ctor_mE45CA150515955650A183C2827A3DA3A8770F80D_RuntimeMethod_var);
		__this->___eventDic_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___eventDic_1), (void*)L_0);
		BaseManager_1__ctor_m447D12F4D58984A74CEC8FBA40A2134E96AC612A(__this, BaseManager_1__ctor_m447D12F4D58984A74CEC8FBA40A2134E96AC612A_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_Multicast(Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* currentDelegate = reinterpret_cast<Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_OpenInst(Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_OpenStatic(Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_OpenStaticInvoker(Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker0::Invoke(__this->___method_ptr_0, method, NULL);
}
void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_ClosedStaticInvoker(Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker1< RuntimeObject* >::Invoke(__this->___method_ptr_0, method, NULL, __this->___m_target_2);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)();
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc();

}
// System.Void Act::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Act__ctor_m8D72A7DBFA4A65A7DFC6312790F5808C2E338383 (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 0;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_Multicast;
}
// System.Void Act::Invoke()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6 (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult Act::BeginInvoke(System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Act_BeginInvoke_m078F8F6FB049C7B8E9D5604757D983005B48C3B5 (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___0_callback, RuntimeObject* ___1_object, const RuntimeMethod* method) 
{
	void *__d_args[1] = {0};
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___0_callback, (RuntimeObject*)___1_object);
}
// System.Void Act::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Act_EndInvoke_mB10EE95D50013AE1F7608AF348DEEEE9EC5392E5 (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void EventDispatcher::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher__ctor_mE5CA2506D8001F54FADEEC748B5254A3190B4C13 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mEE6B30A7F62B93E4D5B5820A8D7FE5DE12CADA5D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m5700B41402680D1EF55FD8A6B8ED41D348D9B83B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<int, Delegate> listeners = new Dictionary<int, Delegate>();
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_0 = (Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675*)il2cpp_codegen_object_new(Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m5700B41402680D1EF55FD8A6B8ED41D348D9B83B(L_0, Dictionary_2__ctor_m5700B41402680D1EF55FD8A6B8ED41D348D9B83B_RuntimeMethod_var);
		__this->___listeners_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___listeners_1), (void*)L_0);
		// public EventDispatcher()
		BaseManager_1__ctor_mEE6B30A7F62B93E4D5B5820A8D7FE5DE12CADA5D(__this, BaseManager_1__ctor_mEE6B30A7F62B93E4D5B5820A8D7FE5DE12CADA5D_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void EventDispatcher::ClearEventListener()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_ClearEventListener_m2C3C30224CAD654FB7D5909B8B95CCDEA5E2F9BB (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Clear_m8EC60FC45B7B894CCEF267E8D0A3DBA52A7897FF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// listeners.Clear();
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_0 = __this->___listeners_1;
		NullCheck(L_0);
		Dictionary_2_Clear_m8EC60FC45B7B894CCEF267E8D0A3DBA52A7897FF(L_0, Dictionary_2_Clear_m8EC60FC45B7B894CCEF267E8D0A3DBA52A7897FF_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void EventDispatcher::AddDelegate(System.Int32,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_AddDelegate_mEDFFFE8E44A2C641D8F30B6286B260660F973B59 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Delegate_t* ___1_listener, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mB7B8E9E63DD9C59E6683CFF7D32E372F86029A5B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	Delegate_t* G_B5_0 = NULL;
	{
		// if (!listeners.TryGetValue(evt, out value))
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_0 = __this->___listeners_1;
		int32_t L_1 = ___0_evt;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
		if (L_2)
		{
			goto IL_001e;
		}
	}
	{
		// listeners.Add(evt, listener);
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_3 = __this->___listeners_1;
		int32_t L_4 = ___0_evt;
		Delegate_t* L_5 = ___1_listener;
		NullCheck(L_3);
		Dictionary_2_Add_mB7B8E9E63DD9C59E6683CFF7D32E372F86029A5B(L_3, L_4, L_5, Dictionary_2_Add_mB7B8E9E63DD9C59E6683CFF7D32E372F86029A5B_RuntimeMethod_var);
		return;
	}

IL_001e:
	{
		// value = (value != null) ? Delegate.Combine(value, listener) : listener;
		Delegate_t* L_6 = V_0;
		if (L_6)
		{
			goto IL_0024;
		}
	}
	{
		Delegate_t* L_7 = ___1_listener;
		G_B5_0 = L_7;
		goto IL_002b;
	}

IL_0024:
	{
		Delegate_t* L_8 = V_0;
		Delegate_t* L_9 = ___1_listener;
		Delegate_t* L_10;
		L_10 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_8, L_9, NULL);
		G_B5_0 = L_10;
	}

IL_002b:
	{
		V_0 = G_B5_0;
		// listeners[evt] = value;
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_11 = __this->___listeners_1;
		int32_t L_12 = ___0_evt;
		Delegate_t* L_13 = V_0;
		NullCheck(L_11);
		Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097(L_11, L_12, L_13, Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void EventDispatcher::RemoveDelegate(System.Int32,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_RemoveDelegate_mFC216692915A8BF2F30CD72E9698E33660CFAD5B (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Delegate_t* ___1_listener, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	{
		// if (listeners.TryGetValue(evt, out func))
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_0 = __this->___listeners_1;
		int32_t L_1 = ___0_evt;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0028;
		}
	}
	{
		// if (func != null)
		Delegate_t* L_3 = V_0;
		if (!L_3)
		{
			goto IL_0028;
		}
	}
	{
		// func = Delegate.Remove(func, listener);
		Delegate_t* L_4 = V_0;
		Delegate_t* L_5 = ___1_listener;
		Delegate_t* L_6;
		L_6 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_4, L_5, NULL);
		V_0 = L_6;
		// listeners[evt] = func;
		Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_7 = __this->___listeners_1;
		int32_t L_8 = ___0_evt;
		Delegate_t* L_9 = V_0;
		NullCheck(L_7);
		Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097(L_7, L_8, L_9, Dictionary_2_set_Item_mDCD9C37228A432FD64CCE813382D0E53888FC097_RuntimeMethod_var);
	}

IL_0028:
	{
		// }
		return;
	}
}
// System.Void EventDispatcher::Regist(System.Int32,Act)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_Regist_m473AB060BE8C601104F2CC2E280EC023632560D7 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* ___1_listener, const RuntimeMethod* method) 
{
	{
		// if (listener == null)
		Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* L_0 = ___1_listener;
		if (L_0)
		{
			goto IL_0004;
		}
	}
	{
		// return;
		return;
	}

IL_0004:
	{
		// AddDelegate(evt, listener);
		int32_t L_1 = ___0_evt;
		Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* L_2 = ___1_listener;
		EventDispatcher_AddDelegate_mEDFFFE8E44A2C641D8F30B6286B260660F973B59(__this, L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void EventDispatcher::UnRegist(System.Int32,Act)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_UnRegist_m42D2B043ECF5B79803759D263C241B48B92D792B (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* ___1_listener, const RuntimeMethod* method) 
{
	{
		// if (listener == null)
		Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* L_0 = ___1_listener;
		if (L_0)
		{
			goto IL_0004;
		}
	}
	{
		// return;
		return;
	}

IL_0004:
	{
		// RemoveDelegate(evt, listener);
		int32_t L_1 = ___0_evt;
		Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* L_2 = ___1_listener;
		EventDispatcher_RemoveDelegate_mFC216692915A8BF2F30CD72E9698E33660CFAD5B(__this, L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void EventDispatcher::DispatchEvent(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher_DispatchEvent_m604C713FACB04919CBF6D4806AA4CD4AA3CFABA2 (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* __this, int32_t ___0_evt, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	try
	{// begin try (depth: 1)
		{
			// if (listeners.TryGetValue(evt, out func) && func != null)
			Dictionary_2_tF625F3980681ED763652575B2FD7C61FF6062675* L_0 = __this->___listeners_1;
			int32_t L_1 = ___0_evt;
			NullCheck(L_0);
			bool L_2;
			L_2 = Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m0000BF8EC0113571A076042F7B90598F8A49AB9B_RuntimeMethod_var);
			if (!L_2)
			{
				goto IL_001e_1;
			}
		}
		{
			Delegate_t* L_3 = V_0;
			if (!L_3)
			{
				goto IL_001e_1;
			}
		}
		{
			// var act = (Act)func;
			Delegate_t* L_4 = V_0;
			// act();
			NullCheck(((Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE*)CastclassSealed((RuntimeObject*)L_4, Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE_il2cpp_TypeInfo_var)));
			Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_inline(((Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE*)CastclassSealed((RuntimeObject*)L_4, Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE_il2cpp_TypeInfo_var)), NULL);
		}

IL_001e_1:
		{
			// }
			goto IL_0037;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0020;
		}
		throw e;
	}

CATCH_0020:
	{// begin catch(System.Exception)
		// UnityEngine.Debug.LogError(e.Message);
		Exception_t* L_5 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		NullCheck(L_5);
		String_t* L_6;
		L_6 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_5);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_6, NULL);
		// UnityEngine.Debug.LogError(e.StackTrace);
		NullCheck(L_5);
		String_t* L_7;
		L_7 = VirtualFuncInvoker0< String_t* >::Invoke(8 /* System.String System.Exception::get_StackTrace() */, L_5);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_7, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION();
		goto IL_0037;
	}// end catch (depth: 1)

IL_0037:
	{
		// }
		return;
	}
}
// System.Void EventDispatcher::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventDispatcher__cctor_m6D7A1B7EB25603B0C00984ADAEF2149619495B35 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static EventDispatcher GameWorldEventDispatcher = new EventDispatcher();
		EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB* L_0 = (EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB*)il2cpp_codegen_object_new(EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		EventDispatcher__ctor_mE5CA2506D8001F54FADEEC748B5254A3190B4C13(L_0, NULL);
		((EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_StaticFields*)il2cpp_codegen_static_fields_for(EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_il2cpp_TypeInfo_var))->___GameWorldEventDispatcher_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_StaticFields*)il2cpp_codegen_static_fields_for(EventDispatcher_t7CA9AE93C32C67703E35056637F9A1E5908F31EB_il2cpp_TypeInfo_var))->___GameWorldEventDispatcher_2), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void InputMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputMgr__ctor_m21A2BA2D0FF003ED29CC9AE94ED7888EAFDE1829 (InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m8062140E42661EB2AB4A1030F79D18744A4B8588_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputMgr_MyUpdate_mE872B96792B1BC670AA4A3B212FDEFD12ABE0084_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public InputMgr()
		BaseManager_1__ctor_m8062140E42661EB2AB4A1030F79D18744A4B8588(__this, BaseManager_1__ctor_m8062140E42661EB2AB4A1030F79D18744A4B8588_RuntimeMethod_var);
		// MonoMgr.Getinstance().AddUpdateListener(MyUpdate);
		MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* L_0;
		L_0 = BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A(BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = (UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)il2cpp_codegen_object_new(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		UnityAction__ctor_mC53E20D6B66E0D5688CD81B88DBB34F5A58B7131(L_1, __this, (intptr_t)((void*)InputMgr_MyUpdate_mE872B96792B1BC670AA4A3B212FDEFD12ABE0084_RuntimeMethod_var), NULL);
		NullCheck(L_0);
		MonoMgr_AddUpdateListener_mA3B87871CCBFF2B79CB83D6A1B604DD3FA36FC6A(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void InputMgr::StartOrEndCheck(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputMgr_StartOrEndCheck_m363A2B2DBFA3D202346E272F55E1CFD7DBDC067E (InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* __this, bool ___0_isOpen, const RuntimeMethod* method) 
{
	{
		// isStart = isOpen;
		bool L_0 = ___0_isOpen;
		__this->___isStart_1 = L_0;
		// }
		return;
	}
}
// System.Void InputMgr::CheckKeyCode(UnityEngine.KeyCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0 (InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral039B89BE7F0419C65251684D8479CFFBEB3B15E2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral36A288CB98EAA1C50F7B49BAB05E2F6C164F41DA);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (Input.GetKeyDown(key))
		int32_t L_0 = ___0_key;
		bool L_1;
		L_1 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		// EventCenter.Getinstance().EventTrigger("???????", key);
		EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* L_2;
		L_2 = BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53(BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var);
		int32_t L_3 = ___0_key;
		NullCheck(L_2);
		EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283(L_2, _stringLiteral039B89BE7F0419C65251684D8479CFFBEB3B15E2, L_3, EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283_RuntimeMethod_var);
	}

IL_0018:
	{
		// if (Input.GetKeyUp(key))
		int32_t L_4 = ___0_key;
		bool L_5;
		L_5 = Input_GetKeyUp_m9A962E395811A9901E7E05F267E198A533DBEF2F(L_4, NULL);
		if (!L_5)
		{
			goto IL_0030;
		}
	}
	{
		// EventCenter.Getinstance().EventTrigger("??????", key);
		EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* L_6;
		L_6 = BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53(BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var);
		int32_t L_7 = ___0_key;
		NullCheck(L_6);
		EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283(L_6, _stringLiteral36A288CB98EAA1C50F7B49BAB05E2F6C164F41DA, L_7, EventCenter_EventTrigger_TisKeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9_m922A20AF013B0EB2A11F820D713E37B72A747283_RuntimeMethod_var);
	}

IL_0030:
	{
		// }
		return;
	}
}
// System.Void InputMgr::MyUpdate()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputMgr_MyUpdate_mE872B96792B1BC670AA4A3B212FDEFD12ABE0084 (InputMgr_tABEFBD6297EE44902B5F8A5E3E311D1527A83D9C* __this, const RuntimeMethod* method) 
{
	{
		// if (!isStart)
		bool L_0 = __this->___isStart_1;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// return;
		return;
	}

IL_0009:
	{
		// CheckKeyCode(KeyCode.W);
		InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0(__this, ((int32_t)119), NULL);
		// CheckKeyCode(KeyCode.S);
		InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0(__this, ((int32_t)115), NULL);
		// CheckKeyCode(KeyCode.A);
		InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0(__this, ((int32_t)97), NULL);
		// CheckKeyCode(KeyCode.D);
		InputMgr_CheckKeyCode_m7D28E9F9FA48C0D565E3DAB3F6C99EC13D3C04E0(__this, ((int32_t)100), NULL);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MonoMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoMgr__ctor_m3746D0779489FFB3FAFA36A7877E65C20C9C3841 (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m3B392CE03E1272ECCA3572C2636F6B8164800BF4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisMonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8_mB2196B16A7FFE8997D15F0C33A4334876F1BA9E7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8ADBEED1B1F615476CC36A651CA71118DDF9447D);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	{
		// public MonoMgr()
		BaseManager_1__ctor_m3B392CE03E1272ECCA3572C2636F6B8164800BF4(__this, BaseManager_1__ctor_m3B392CE03E1272ECCA3572C2636F6B8164800BF4_RuntimeMethod_var);
		// GameObject obj = new GameObject("MonoController");
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_0, _stringLiteral8ADBEED1B1F615476CC36A651CA71118DDF9447D, NULL);
		V_0 = L_0;
		// controller = obj.AddComponent<MonoController>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = V_0;
		NullCheck(L_1);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_2;
		L_2 = GameObject_AddComponent_TisMonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8_mB2196B16A7FFE8997D15F0C33A4334876F1BA9E7(L_1, GameObject_AddComponent_TisMonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8_mB2196B16A7FFE8997D15F0C33A4334876F1BA9E7_RuntimeMethod_var);
		__this->___controller_1 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___controller_1), (void*)L_2);
		// }
		return;
	}
}
// System.Void MonoMgr::AddUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoMgr_AddUpdateListener_mA3B87871CCBFF2B79CB83D6A1B604DD3FA36FC6A (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) 
{
	{
		// controller.AddUpdateListener(fun);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_0 = __this->___controller_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = ___0_fun;
		NullCheck(L_0);
		MonoController_AddUpdateListener_mEB7BC2F32C90688ABEBC26F6FC71133766B62FF4(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void MonoMgr::RemoveUpdateListener(UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoMgr_RemoveUpdateListener_m676FA567784A23ABD79564CCB976585125A30E30 (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___0_fun, const RuntimeMethod* method) 
{
	{
		// controller.RemoveUpdateListener(fun);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_0 = __this->___controller_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = ___0_fun;
		NullCheck(L_0);
		MonoController_RemoveUpdateListener_m8DFE3D0984F21C59AE0A9A7C1EBBA62CC1320672(L_0, L_1, NULL);
		// }
		return;
	}
}
// UnityEngine.Coroutine MonoMgr::StartCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoMgr_StartCoroutine_m1B651E11C49C987BA6649A89284AE7FBBF081F2B (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) 
{
	{
		// return controller.StartCoroutine(routine);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_0 = __this->___controller_1;
		RuntimeObject* L_1 = ___0_routine;
		NullCheck(L_0);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_2;
		L_2 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(L_0, L_1, NULL);
		return L_2;
	}
}
// UnityEngine.Coroutine MonoMgr::StartCoroutine(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoMgr_StartCoroutine_m14901F54A548F522547EEF8E21ABFAE5852D7B9E (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, String_t* ___0_methodName, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	{
		// return controller.StartCoroutine(methodName, value);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_0 = __this->___controller_1;
		String_t* L_1 = ___0_methodName;
		RuntimeObject* L_2 = ___1_value;
		NullCheck(L_0);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_3;
		L_3 = MonoBehaviour_StartCoroutine_mD754B72714F15210DDA429A096D853852FF437AB(L_0, L_1, L_2, NULL);
		return L_3;
	}
}
// UnityEngine.Coroutine MonoMgr::StartCoroutine(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoMgr_StartCoroutine_mF32C64EF931E24FA806ADF8E412916D530D38FF4 (MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* __this, String_t* ___0_methodName, const RuntimeMethod* method) 
{
	{
		// return controller.StartCoroutine(methodName);
		MonoController_t5C72C2CC9CAB5FA1E5F1077D2158B3E10EA52AA8* L_0 = __this->___controller_1;
		String_t* L_1 = ___0_methodName;
		NullCheck(L_0);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_2;
		L_2 = MonoBehaviour_StartCoroutine_m10C4B693B96175C42B0FD00911E072701C220DB4(L_0, L_1, NULL);
		return L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MusicMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr__ctor_m85261245C4DC51D3C37DA47FF311D46724482F7E (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m90F17B40FD5672642AAA8231A17565250792C81D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m1572AF991CD3CD21B43B0D6F699FE6296DEDF9E7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m985F72633850464A3301F658B9CD510F7ADCDC33_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MusicMgr_Update_m4D7AD42E819A73E226CE0582614CAB91B584A6FC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4B21C6381F4562924241036A9190E1FD19FD99B2);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private string soundUrl = "AudioSound/";
		__this->___soundUrl_1 = _stringLiteral4B21C6381F4562924241036A9190E1FD19FD99B2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___soundUrl_1), (void*)_stringLiteral4B21C6381F4562924241036A9190E1FD19FD99B2);
		// private List<AudioClip> audioClips = new List<AudioClip>();
		List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* L_0 = (List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F*)il2cpp_codegen_object_new(List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_m985F72633850464A3301F658B9CD510F7ADCDC33(L_0, List_1__ctor_m985F72633850464A3301F658B9CD510F7ADCDC33_RuntimeMethod_var);
		__this->___audioClips_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___audioClips_2), (void*)L_0);
		// private float bkValue = 1;
		__this->___bkValue_4 = (1.0f);
		// private List<AudioSource> soundList = new List<AudioSource>();
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_1 = (List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235*)il2cpp_codegen_object_new(List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		List_1__ctor_m1572AF991CD3CD21B43B0D6F699FE6296DEDF9E7(L_1, List_1__ctor_m1572AF991CD3CD21B43B0D6F699FE6296DEDF9E7_RuntimeMethod_var);
		__this->___soundList_6 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___soundList_6), (void*)L_1);
		// private float soundValue = 1;
		__this->___soundValue_7 = (1.0f);
		// public MusicMgr()
		BaseManager_1__ctor_m90F17B40FD5672642AAA8231A17565250792C81D(__this, BaseManager_1__ctor_m90F17B40FD5672642AAA8231A17565250792C81D_RuntimeMethod_var);
		// MonoMgr.Getinstance().AddUpdateListener(Update);
		MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* L_2;
		L_2 = BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A(BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_3 = (UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7*)il2cpp_codegen_object_new(UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		UnityAction__ctor_mC53E20D6B66E0D5688CD81B88DBB34F5A58B7131(L_3, __this, (intptr_t)((void*)MusicMgr_Update_m4D7AD42E819A73E226CE0582614CAB91B584A6FC_RuntimeMethod_var), NULL);
		NullCheck(L_2);
		MonoMgr_AddUpdateListener_mA3B87871CCBFF2B79CB83D6A1B604DD3FA36FC6A(L_2, L_3, NULL);
		// }
		return;
	}
}
// System.Void MusicMgr::init(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_init_mFC2242B10E2BC75FF00C2E16BE3ACBE85764028F (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_audio_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// bkMusic = audio_obj.AddComponent<AudioSource>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_audio_obj;
		NullCheck(L_0);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_1;
		L_1 = GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14(L_0, GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		__this->___bkMusic_3 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___bkMusic_3), (void*)L_1);
		// }
		return;
	}
}
// System.Void MusicMgr::PreLoadRes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_PreLoadRes_mEBDE9B31B189A9E43361641FFB9ACB6E6403BA82 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m51C49FD07D05048E52C4324E83FEC9BD2174F6B7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResMgr_LoadAll_TisAudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20_m0E51BEBC9135361F746488BE347CCF40C71FE769_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* V_0 = NULL;
	int32_t V_1 = 0;
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* V_2 = NULL;
	{
		// ResMgr resMgr = ResMgr.Getinstance();
		ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* L_0;
		L_0 = BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC(BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		// AudioClip[] _audioClips = resMgr.LoadAll<AudioClip>(soundUrl);
		String_t* L_1 = __this->___soundUrl_1;
		NullCheck(L_0);
		AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* L_2;
		L_2 = ResMgr_LoadAll_TisAudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20_m0E51BEBC9135361F746488BE347CCF40C71FE769(L_0, L_1, (bool)0, ResMgr_LoadAll_TisAudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20_m0E51BEBC9135361F746488BE347CCF40C71FE769_RuntimeMethod_var);
		// foreach (var item in _audioClips)
		V_0 = L_2;
		V_1 = 0;
		goto IL_002a;
	}

IL_0016:
	{
		// foreach (var item in _audioClips)
		AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* L_3 = V_0;
		int32_t L_4 = V_1;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		// audioClips.Add(item);
		List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* L_7 = __this->___audioClips_2;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_8 = V_2;
		NullCheck(L_7);
		List_1_Add_m51C49FD07D05048E52C4324E83FEC9BD2174F6B7_inline(L_7, L_8, List_1_Add_m51C49FD07D05048E52C4324E83FEC9BD2174F6B7_RuntimeMethod_var);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_002a:
	{
		// foreach (var item in _audioClips)
		int32_t L_10 = V_1;
		AudioClipU5BU5D_t916722468F7EDCFA833318C35CD7D41097D75D31* L_11 = V_0;
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_0016;
		}
	}
	{
		// }
		return;
	}
}
// System.Void MusicMgr::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_Update_m4D7AD42E819A73E226CE0582614CAB91B584A6FC (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m023E515689BBE45DA9EE94BE763578B854A74CF2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// for (int i = soundList.Count - 1; i >= 0; --i)
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_0 = __this->___soundList_6;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_inline(L_0, List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_RuntimeMethod_var);
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_1, 1));
		goto IL_0044;
	}

IL_0010:
	{
		// if (!soundList[i].isPlaying)
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_2 = __this->___soundList_6;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_4;
		L_4 = List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6(L_2, L_3, List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var);
		NullCheck(L_4);
		bool L_5;
		L_5 = AudioSource_get_isPlaying_mC203303F2F7146B2C056CB47B9391463FDF408FC(L_4, NULL);
		if (L_5)
		{
			goto IL_0040;
		}
	}
	{
		// GameObject.Destroy(soundList[i]);
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_6 = __this->___soundList_6;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_8;
		L_8 = List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6(L_6, L_7, List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_8, NULL);
		// soundList.RemoveAt(i);
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_9 = __this->___soundList_6;
		int32_t L_10 = V_0;
		NullCheck(L_9);
		List_1_RemoveAt_m023E515689BBE45DA9EE94BE763578B854A74CF2(L_9, L_10, List_1_RemoveAt_m023E515689BBE45DA9EE94BE763578B854A74CF2_RuntimeMethod_var);
	}

IL_0040:
	{
		// for (int i = soundList.Count - 1; i >= 0; --i)
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
	}

IL_0044:
	{
		// for (int i = soundList.Count - 1; i >= 0; --i)
		int32_t L_12 = V_0;
		if ((((int32_t)L_12) >= ((int32_t)0)))
		{
			goto IL_0010;
		}
	}
	{
		// }
		return;
	}
}
// UnityEngine.AudioClip MusicMgr::GetAudioClipByName(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* MusicMgr_GetAudioClipByName_m3477B862E0DC8B63AACAB1E903381832F4ED5C6F (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, String_t* ___0_clipName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Find_m7D74D30D22001969B022341FCB9E7BB633C9638F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass11_0_U3CGetAudioClipByNameU3Eb__0_m9228114D053677A9B9902C7BA0C03E9BFA65DAB9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* V_0 = NULL;
	{
		U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* L_0 = (U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1*)il2cpp_codegen_object_new(U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CU3Ec__DisplayClass11_0__ctor_mD006ED08E4FB895F2F9F231072C827E9EDB53041(L_0, NULL);
		V_0 = L_0;
		U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* L_1 = V_0;
		String_t* L_2 = ___0_clipName;
		NullCheck(L_1);
		L_1->___clipName_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___clipName_0), (void*)L_2);
		// return audioClips.Find(clip => clip.name == clipName);
		List_1_t33C1B21871505CF0516B63C148CD83EDA452BB5F* L_3 = __this->___audioClips_2;
		U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* L_4 = V_0;
		Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6* L_5 = (Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6*)il2cpp_codegen_object_new(Predicate_1_t187B849CC4AAA731C113AC14B0427C5E4CEF58D6_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Predicate_1__ctor_m7223B14FD3962CE47DAC436DA2661ECD6F3DC93E(L_5, L_4, (intptr_t)((void*)U3CU3Ec__DisplayClass11_0_U3CGetAudioClipByNameU3Eb__0_m9228114D053677A9B9902C7BA0C03E9BFA65DAB9_RuntimeMethod_var), NULL);
		NullCheck(L_3);
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_6;
		L_6 = List_1_Find_m7D74D30D22001969B022341FCB9E7BB633C9638F(L_3, L_5, List_1_Find_m7D74D30D22001969B022341FCB9E7BB633C9638F_RuntimeMethod_var);
		return L_6;
	}
}
// System.Void MusicMgr::PlayBkMusic(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_PlayBkMusic_m2E08BFD95DCBFF87AAD5F21DB422C5901E1835F5 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral02AAF53D94E93084B4B52EF4C1C98D9C7E4D02B4);
		s_Il2CppMethodInitialized = true;
	}
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* V_0 = NULL;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_1 = NULL;
	{
		// if (bkMusic == null)
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_0 = __this->___bkMusic_3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_002b;
		}
	}
	{
		// GameObject obj = new GameObject();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GameObject__ctor_m7D0340DE160786E6EFA8DABD39EC3B694DA30AAD(L_2, NULL);
		V_1 = L_2;
		// obj.name = "BkMusic";
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = V_1;
		NullCheck(L_3);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47(L_3, _stringLiteral02AAF53D94E93084B4B52EF4C1C98D9C7E4D02B4, NULL);
		// bkMusic = obj.AddComponent<AudioSource>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = V_1;
		NullCheck(L_4);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_5;
		L_5 = GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14(L_4, GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		__this->___bkMusic_3 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___bkMusic_3), (void*)L_5);
	}

IL_002b:
	{
		// AudioClip clip = GetAudioClipByName(name);
		String_t* L_6 = ___0_name;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_7;
		L_7 = MusicMgr_GetAudioClipByName_m3477B862E0DC8B63AACAB1E903381832F4ED5C6F(__this, L_6, NULL);
		V_0 = L_7;
		// if (!clip) return;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_8 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_9;
		L_9 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_8, NULL);
		if (L_9)
		{
			goto IL_003c;
		}
	}
	{
		// if (!clip) return;
		return;
	}

IL_003c:
	{
		// bkMusic.clip = clip;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_10 = __this->___bkMusic_3;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_11 = V_0;
		NullCheck(L_10);
		AudioSource_set_clip_mFF441895E274286C88D9C75ED5CA1B1B39528D70(L_10, L_11, NULL);
		// bkMusic.loop = true;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_12 = __this->___bkMusic_3;
		NullCheck(L_12);
		AudioSource_set_loop_m834A590939D8456008C0F897FD80B0ECFFB7FE56(L_12, (bool)1, NULL);
		// bkMusic.volume = bkValue;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_13 = __this->___bkMusic_3;
		float L_14 = __this->___bkValue_4;
		NullCheck(L_13);
		AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0(L_13, L_14, NULL);
		// bkMusic.Play();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_15 = __this->___bkMusic_3;
		NullCheck(L_15);
		AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3(L_15, NULL);
		// }
		return;
	}
}
// System.Void MusicMgr::PauseBKMusic()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_PauseBKMusic_mA77998B85D0B1B992D507B4F5481522CE12BEC1A (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (bkMusic == null)
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_0 = __this->___bkMusic_3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// return;
		return;
	}

IL_000f:
	{
		// bkMusic.Pause();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_2 = __this->___bkMusic_3;
		NullCheck(L_2);
		AudioSource_Pause_m2C2A09359E8AA924FEADECC1AFEA519B3C915B26(L_2, NULL);
		// }
		return;
	}
}
// System.Void MusicMgr::StopBKMusic()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_StopBKMusic_m7D691944558A9F8D4AF0366FA0AD6EDD0FB224D1 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (bkMusic == null)
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_0 = __this->___bkMusic_3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// return;
		return;
	}

IL_000f:
	{
		// bkMusic.Stop();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_2 = __this->___bkMusic_3;
		NullCheck(L_2);
		AudioSource_Stop_m318F17F17A147C77FF6E0A5A7A6BE057DB90F537(L_2, NULL);
		// }
		return;
	}
}
// System.Void MusicMgr::ChangeBKValue(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_ChangeBKValue_mFFC32EC525DE01A783DFF68FDB2FD35EBDBFAF6A (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, float ___0_v, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// bkValue = v;
		float L_0 = ___0_v;
		__this->___bkValue_4 = L_0;
		// if (bkMusic == null)
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_1 = __this->___bkMusic_3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_0016;
		}
	}
	{
		// return;
		return;
	}

IL_0016:
	{
		// bkMusic.volume = bkValue;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_3 = __this->___bkMusic_3;
		float L_4 = __this->___bkValue_4;
		NullCheck(L_3);
		AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0(L_3, L_4, NULL);
		// }
		return;
	}
}
// System.Void MusicMgr::PlaySound(System.String,System.Boolean,System.Boolean,UnityEngine.Events.UnityAction`1<UnityEngine.AudioSource>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_PlaySound_mAAE0531527960D5DCE7035BD0117868BBDF4BB90 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, String_t* ___0_name, bool ___1_isLoop, bool ___2_rotationSound, UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6* ___3_callBack, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m4F30DAB8E5B57E8DB6BD8C0C3BB11CCB57690C4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m854AB1F4912F4A70C478FAE8E282C8F6CE880550_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB3C34217CBB8F650ED8F6E70B410A604371E2EF1);
		s_Il2CppMethodInitialized = true;
	}
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* V_0 = NULL;
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* V_1 = NULL;
	{
		// if (soundObj == null)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___soundObj_5;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0029;
		}
	}
	{
		// soundObj = new GameObject();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GameObject__ctor_m7D0340DE160786E6EFA8DABD39EC3B694DA30AAD(L_2, NULL);
		__this->___soundObj_5 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___soundObj_5), (void*)L_2);
		// soundObj.name = "Sound";
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = __this->___soundObj_5;
		NullCheck(L_3);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47(L_3, _stringLiteralB3C34217CBB8F650ED8F6E70B410A604371E2EF1, NULL);
	}

IL_0029:
	{
		// AudioClip clip = GetAudioClipByName(name);
		String_t* L_4 = ___0_name;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_5;
		L_5 = MusicMgr_GetAudioClipByName_m3477B862E0DC8B63AACAB1E903381832F4ED5C6F(__this, L_4, NULL);
		V_0 = L_5;
		// if (!clip) return;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_6 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_7;
		L_7 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_6, NULL);
		if (L_7)
		{
			goto IL_003a;
		}
	}
	{
		// if (!clip) return;
		return;
	}

IL_003a:
	{
		// AudioSource source = soundObj.GetComponent<AudioSource>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_8 = __this->___soundObj_5;
		NullCheck(L_8);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_9;
		L_9 = GameObject_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m4F30DAB8E5B57E8DB6BD8C0C3BB11CCB57690C4A(L_8, GameObject_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m4F30DAB8E5B57E8DB6BD8C0C3BB11CCB57690C4A_RuntimeMethod_var);
		V_1 = L_9;
		// if (!source) {
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_10 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_11;
		L_11 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_10, NULL);
		if (L_11)
		{
			goto IL_005a;
		}
	}
	{
		// source = soundObj.AddComponent<AudioSource>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_12 = __this->___soundObj_5;
		NullCheck(L_12);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_13;
		L_13 = GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14(L_12, GameObject_AddComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m0E8EFDB9B3D8DF1ADE10C56D3168A9C1BA19BF14_RuntimeMethod_var);
		V_1 = L_13;
	}

IL_005a:
	{
		// if (rotationSound && source.isPlaying)
		bool L_14 = ___2_rotationSound;
		if (!L_14)
		{
			goto IL_006b;
		}
	}
	{
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_15 = V_1;
		NullCheck(L_15);
		bool L_16;
		L_16 = AudioSource_get_isPlaying_mC203303F2F7146B2C056CB47B9391463FDF408FC(L_15, NULL);
		if (!L_16)
		{
			goto IL_006b;
		}
	}
	{
		// source.Stop();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_17 = V_1;
		NullCheck(L_17);
		AudioSource_Stop_m318F17F17A147C77FF6E0A5A7A6BE057DB90F537(L_17, NULL);
	}

IL_006b:
	{
		// source.clip = clip;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_18 = V_1;
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_19 = V_0;
		NullCheck(L_18);
		AudioSource_set_clip_mFF441895E274286C88D9C75ED5CA1B1B39528D70(L_18, L_19, NULL);
		// source.loop = isLoop;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_20 = V_1;
		bool L_21 = ___1_isLoop;
		NullCheck(L_20);
		AudioSource_set_loop_m834A590939D8456008C0F897FD80B0ECFFB7FE56(L_20, L_21, NULL);
		// source.volume = soundValue;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_22 = V_1;
		float L_23 = __this->___soundValue_7;
		NullCheck(L_22);
		AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0(L_22, L_23, NULL);
		// source.Play();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_24 = V_1;
		NullCheck(L_24);
		AudioSource_Play_m95DF07111C61D0E0F00257A00384D31531D590C3(L_24, NULL);
		// soundList.Add(source);
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_25 = __this->___soundList_6;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_26 = V_1;
		NullCheck(L_25);
		List_1_Add_m854AB1F4912F4A70C478FAE8E282C8F6CE880550_inline(L_25, L_26, List_1_Add_m854AB1F4912F4A70C478FAE8E282C8F6CE880550_RuntimeMethod_var);
		// if (callBack != null)
		UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6* L_27 = ___3_callBack;
		if (!L_27)
		{
			goto IL_00a3;
		}
	}
	{
		// callBack(source);
		UnityAction_1_tF30F2C795EF0D40DC13382C0BCFE41BCAD929AA6* L_28 = ___3_callBack;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_29 = V_1;
		NullCheck(L_28);
		UnityAction_1_Invoke_m93F914E6E8E50FAAD27933A3291E1AB6E6CD144D_inline(L_28, L_29, NULL);
	}

IL_00a3:
	{
		// }
		return;
	}
}
// System.Void MusicMgr::ChangeSoundValue(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_ChangeSoundValue_m0DE9661522C794964FE2DA60AC7E66F22D00BB59 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, float ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// soundValue = value;
		float L_0 = ___0_value;
		__this->___soundValue_7 = L_0;
		// for (int i = 0; i < soundList.Count; ++i)
		V_0 = 0;
		goto IL_0021;
	}

IL_000b:
	{
		// soundList[i].volume = value;
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_1 = __this->___soundList_6;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_3;
		L_3 = List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6(L_1, L_2, List_1_get_Item_m819B6C1A78476CF0262F3D90C612006783F22EB6_RuntimeMethod_var);
		float L_4 = ___0_value;
		NullCheck(L_3);
		AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0(L_3, L_4, NULL);
		// for (int i = 0; i < soundList.Count; ++i)
		int32_t L_5 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0021:
	{
		// for (int i = 0; i < soundList.Count; ++i)
		int32_t L_6 = V_0;
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_7 = __this->___soundList_6;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_inline(L_7, List_1_get_Count_m7B789802BC75721DA5E775D38FEA0F4B1494F612_RuntimeMethod_var);
		if ((((int32_t)L_6) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		// }
		return;
	}
}
// System.Void MusicMgr::StopSound(UnityEngine.AudioSource)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MusicMgr_StopSound_m45F681178EA6817EF0294B5CD2D67B8AC8A076B9 (MusicMgr_tA8E2713C05E6071C91246DAA86D007FB86BEA1CB* __this, AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Contains_m85C62F7184BE9A0919BFBB82DE91D6C4AB143BD6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Remove_m7F54CE1C95A107E8F4A696104788E78107528DDB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (soundList.Contains(source))
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_0 = __this->___soundList_6;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_1 = ___0_source;
		NullCheck(L_0);
		bool L_2;
		L_2 = List_1_Contains_m85C62F7184BE9A0919BFBB82DE91D6C4AB143BD6(L_0, L_1, List_1_Contains_m85C62F7184BE9A0919BFBB82DE91D6C4AB143BD6_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0027;
		}
	}
	{
		// soundList.Remove(source);
		List_1_t0EDD1795F87849390F5CA17CBABE75183BE4E235* L_3 = __this->___soundList_6;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_4 = ___0_source;
		NullCheck(L_3);
		bool L_5;
		L_5 = List_1_Remove_m7F54CE1C95A107E8F4A696104788E78107528DDB(L_3, L_4, List_1_Remove_m7F54CE1C95A107E8F4A696104788E78107528DDB_RuntimeMethod_var);
		// source.Stop();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_6 = ___0_source;
		NullCheck(L_6);
		AudioSource_Stop_m318F17F17A147C77FF6E0A5A7A6BE057DB90F537(L_6, NULL);
		// GameObject.Destroy(source);
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_7 = ___0_source;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_7, NULL);
	}

IL_0027:
	{
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MusicMgr/<>c__DisplayClass11_0::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass11_0__ctor_mD006ED08E4FB895F2F9F231072C827E9EDB53041 (U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Boolean MusicMgr/<>c__DisplayClass11_0::<GetAudioClipByName>b__0(UnityEngine.AudioClip)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec__DisplayClass11_0_U3CGetAudioClipByNameU3Eb__0_m9228114D053677A9B9902C7BA0C03E9BFA65DAB9 (U3CU3Ec__DisplayClass11_0_tD9857AAE8601E88A659EF0F8C2DE1E6F68E06FE1* __this, AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___0_clip, const RuntimeMethod* method) 
{
	{
		// return audioClips.Find(clip => clip.name == clipName);
		AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* L_0 = ___0_clip;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_0, NULL);
		String_t* L_2 = __this->___clipName_0;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_1, L_2, NULL);
		return L_3;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void PoolData::.ctor(UnityEngine.GameObject,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolData__ctor_mBE70CAE9EBCD5C946D34BEDC59DEC5FDC74D8034 (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_obj, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___1_poolObj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public PoolData(GameObject obj, GameObject poolObj)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// fatherObj = new GameObject(obj.name);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_obj;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_0, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_2, L_1, NULL);
		__this->___fatherObj_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___fatherObj_0), (void*)L_2);
		// fatherObj.transform.parent = poolObj.transform;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = __this->___fatherObj_0;
		NullCheck(L_3);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_4;
		L_4 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_3, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = ___1_poolObj;
		NullCheck(L_5);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_5, NULL);
		NullCheck(L_4);
		Transform_set_parent_m9BD5E563B539DD5BEC342736B03F97B38A243234(L_4, L_6, NULL);
		// poolList = new List<GameObject>() { };
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_7 = (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*)il2cpp_codegen_object_new(List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC(L_7, List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		__this->___poolList_1 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___poolList_1), (void*)L_7);
		// PushObj(obj);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_8 = ___0_obj;
		PoolData_PushObj_m89E38D986DAD45CC4A70CF6C9546A1FE175FA60B(__this, L_8, NULL);
		// }
		return;
	}
}
// System.Void PoolData::PushObj(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolData_PushObj_m89E38D986DAD45CC4A70CF6C9546A1FE175FA60B (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// obj.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_obj;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// poolList.Add(obj);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_1 = __this->___poolList_1;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = ___0_obj;
		NullCheck(L_1);
		List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline(L_1, L_2, List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		// obj.transform.SetParent(fatherObj.transform);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = ___0_obj;
		NullCheck(L_3);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_4;
		L_4 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_3, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = __this->___fatherObj_0;
		NullCheck(L_5);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_5, NULL);
		NullCheck(L_4);
		Transform_SetParent_m6677538B60246D958DD91F931C50F969CCBB5250(L_4, L_6, NULL);
		// }
		return;
	}
}
// UnityEngine.GameObject PoolData::GetObj()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PoolData_GetObj_m760D25B289FD5BF400C34811EF17B6D93620465F (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// obj = poolList[0];
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_0 = __this->___poolList_1;
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979(L_0, 0, List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979_RuntimeMethod_var);
		// poolList.RemoveAt(0);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_2 = __this->___poolList_1;
		NullCheck(L_2);
		List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260(L_2, 0, List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260_RuntimeMethod_var);
		// obj.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = L_1;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)1, NULL);
		// obj.transform.parent = null;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = L_3;
		NullCheck(L_4);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_5;
		L_5 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_4, NULL);
		NullCheck(L_5);
		Transform_set_parent_m9BD5E563B539DD5BEC342736B03F97B38A243234(L_5, (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1*)NULL, NULL);
		// return obj;
		return L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void PoolMgr::GetObj(System.String,System.String,UnityEngine.Events.UnityAction`1<UnityEngine.GameObject>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolMgr_GetObj_mDFEAFCD692C893A6CBBB9528BB6A0886F66DBC81 (PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F* __this, String_t* ___0_name, String_t* ___1_path, UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* ___2_callBack, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResMgr_LoadAsync_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_mAAEEB26879FEB6A44035D9B29A86CDEC4013F84F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass2_0_U3CGetObjU3Eb__0_mAC15ECEB39E40CD3936C8B2650E7A84A85D9625F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* V_0 = NULL;
	{
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_0 = (U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF*)il2cpp_codegen_object_new(U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CU3Ec__DisplayClass2_0__ctor_mE4FBE720A9EF4E79A8E175641CA71D2041C29E83(L_0, NULL);
		V_0 = L_0;
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_1 = V_0;
		String_t* L_2 = ___0_name;
		NullCheck(L_1);
		L_1->___name_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___name_0), (void*)L_2);
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_3 = V_0;
		UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* L_4 = ___2_callBack;
		NullCheck(L_3);
		L_3->___callBack_1 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&L_3->___callBack_1), (void*)L_4);
		// if (poolDic.ContainsKey(name) && poolDic[name].poolList.Count > 0)
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_5 = __this->___poolDic_1;
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_6 = V_0;
		NullCheck(L_6);
		String_t* L_7 = L_6->___name_0;
		NullCheck(L_5);
		bool L_8;
		L_8 = Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366(L_5, L_7, Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366_RuntimeMethod_var);
		if (!L_8)
		{
			goto IL_0067;
		}
	}
	{
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_9 = __this->___poolDic_1;
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_10 = V_0;
		NullCheck(L_10);
		String_t* L_11 = L_10->___name_0;
		NullCheck(L_9);
		PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* L_12;
		L_12 = Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442(L_9, L_11, Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var);
		NullCheck(L_12);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_13 = L_12->___poolList_1;
		NullCheck(L_13);
		int32_t L_14;
		L_14 = List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_inline(L_13, List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_RuntimeMethod_var);
		if ((((int32_t)L_14) <= ((int32_t)0)))
		{
			goto IL_0067;
		}
	}
	{
		// callBack(poolDic[name].GetObj());
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_15 = V_0;
		NullCheck(L_15);
		UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* L_16 = L_15->___callBack_1;
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_17 = __this->___poolDic_1;
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_18 = V_0;
		NullCheck(L_18);
		String_t* L_19 = L_18->___name_0;
		NullCheck(L_17);
		PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* L_20;
		L_20 = Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442(L_17, L_19, Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var);
		NullCheck(L_20);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_21;
		L_21 = PoolData_GetObj_m760D25B289FD5BF400C34811EF17B6D93620465F(L_20, NULL);
		NullCheck(L_16);
		UnityAction_1_Invoke_mC0B03E675E5A61F6BDCA0F469FA5CCF9C4E52159_inline(L_16, L_21, NULL);
		return;
	}

IL_0067:
	{
		// ResMgr.Getinstance().LoadAsync<GameObject>(path, (o) =>
		// {
		//     o.name = name;
		//     callBack(o);
		// });
		ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* L_22;
		L_22 = BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC(BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		String_t* L_23 = ___1_path;
		U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* L_24 = V_0;
		UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* L_25 = (UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187*)il2cpp_codegen_object_new(UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187_il2cpp_TypeInfo_var);
		NullCheck(L_25);
		UnityAction_1__ctor_m4AAE7BBE595D82E15A5A774EEB588EA82A63C16E(L_25, L_24, (intptr_t)((void*)U3CU3Ec__DisplayClass2_0_U3CGetObjU3Eb__0_mAC15ECEB39E40CD3936C8B2650E7A84A85D9625F_RuntimeMethod_var), NULL);
		NullCheck(L_22);
		ResMgr_LoadAsync_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_mAAEEB26879FEB6A44035D9B29A86CDEC4013F84F(L_22, L_23, L_25, ResMgr_LoadAsync_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_mAAEEB26879FEB6A44035D9B29A86CDEC4013F84F_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void PoolMgr::PushObj(System.String,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolMgr_PushObj_m853348A77BD55B6A2FE9048211309F5E65788A0A (PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F* __this, String_t* ___0_name, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___1_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mC87FA1BC7656A1A1B43AEC922DB326EE287988C9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6F8680E036372B06F0D00587303C00203DFE6F0D);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (poolObj == null)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___poolObj_2;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_001e;
		}
	}
	{
		// poolObj = new GameObject("Pool");
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_2, _stringLiteral6F8680E036372B06F0D00587303C00203DFE6F0D, NULL);
		__this->___poolObj_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___poolObj_2), (void*)L_2);
	}

IL_001e:
	{
		// obj.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = ___1_obj;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)0, NULL);
		// if (poolDic.ContainsKey(name))
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_4 = __this->___poolDic_1;
		String_t* L_5 = ___0_name;
		NullCheck(L_4);
		bool L_6;
		L_6 = Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366(L_4, L_5, Dictionary_2_ContainsKey_m0D263999F4CDA76FF30085CAA250AF812C973366_RuntimeMethod_var);
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		// poolDic[name].PushObj(obj);
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_7 = __this->___poolDic_1;
		String_t* L_8 = ___0_name;
		NullCheck(L_7);
		PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* L_9;
		L_9 = Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442(L_7, L_8, Dictionary_2_get_Item_mCB0EED3B694248EAD28B23DA65C04D3A8DF64442_RuntimeMethod_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_10 = ___1_obj;
		NullCheck(L_9);
		PoolData_PushObj_m89E38D986DAD45CC4A70CF6C9546A1FE175FA60B(L_9, L_10, NULL);
		return;
	}

IL_0046:
	{
		// poolDic.Add(name, new PoolData(obj, poolObj));
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_11 = __this->___poolDic_1;
		String_t* L_12 = ___0_name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13 = ___1_obj;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14 = __this->___poolObj_2;
		PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6* L_15 = (PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6*)il2cpp_codegen_object_new(PoolData_tBE0CEA1502416A7B9C8F9CE864636FDD930BE4C6_il2cpp_TypeInfo_var);
		NullCheck(L_15);
		PoolData__ctor_mBE70CAE9EBCD5C946D34BEDC59DEC5FDC74D8034(L_15, L_13, L_14, NULL);
		NullCheck(L_11);
		Dictionary_2_Add_mC87FA1BC7656A1A1B43AEC922DB326EE287988C9(L_11, L_12, L_15, Dictionary_2_Add_mC87FA1BC7656A1A1B43AEC922DB326EE287988C9_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void PoolMgr::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolMgr_Clear_mC70976716210F42F77A917EF18A7CF7F72B9E14D (PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Clear_m08917F7954D626ED30A494E9127F69C3002BE29A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// poolDic.Clear();
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_0 = __this->___poolDic_1;
		NullCheck(L_0);
		Dictionary_2_Clear_m08917F7954D626ED30A494E9127F69C3002BE29A(L_0, Dictionary_2_Clear_m08917F7954D626ED30A494E9127F69C3002BE29A_RuntimeMethod_var);
		// poolObj = null;
		__this->___poolObj_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___poolObj_2), (void*)(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL);
		// }
		return;
	}
}
// System.Void PoolMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolMgr__ctor_mD280D14530E79788DAB7E5BAECA3B068494A38D7 (PoolMgr_t0018F0D512961ACFD0D0EF16FA2863C64BA5838F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mA6B8F030965B62068872EE479BB3B09A3732A1E1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mE4874F66ADA7FCBE7FB1BEDBA767DCEC3CCDF624_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public Dictionary<string, PoolData> poolDic = new Dictionary<string, PoolData>();
		Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5* L_0 = (Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5*)il2cpp_codegen_object_new(Dictionary_2_t276EB8743CBB1E4F8CD23AC4800506E245786DC5_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mE4874F66ADA7FCBE7FB1BEDBA767DCEC3CCDF624(L_0, Dictionary_2__ctor_mE4874F66ADA7FCBE7FB1BEDBA767DCEC3CCDF624_RuntimeMethod_var);
		__this->___poolDic_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___poolDic_1), (void*)L_0);
		BaseManager_1__ctor_mA6B8F030965B62068872EE479BB3B09A3732A1E1(__this, BaseManager_1__ctor_mA6B8F030965B62068872EE479BB3B09A3732A1E1_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void PoolMgr/<>c__DisplayClass2_0::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass2_0__ctor_mE4FBE720A9EF4E79A8E175641CA71D2041C29E83 (U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Void PoolMgr/<>c__DisplayClass2_0::<GetObj>b__0(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass2_0_U3CGetObjU3Eb__0_mAC15ECEB39E40CD3936C8B2650E7A84A85D9625F (U3CU3Ec__DisplayClass2_0_t2B41F3ED30DAF7106A3558E8C22DCF84E5CB99CF* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_o, const RuntimeMethod* method) 
{
	{
		// o.name = name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_o;
		String_t* L_1 = __this->___name_0;
		NullCheck(L_0);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47(L_0, L_1, NULL);
		// callBack(o);
		UnityAction_1_tD54AA8F82EC6FBE26C68406BD3CB52F8CC4BF187* L_2 = __this->___callBack_1;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = ___0_o;
		NullCheck(L_2);
		UnityAction_1_Invoke_mC0B03E675E5A61F6BDCA0F469FA5CCF9C4E52159_inline(L_2, L_3, NULL);
		// });
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.GameObject PoolManage::Getobj(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PoolManage_Getobj_mA52AFD734563EFF0B3B2F37A75DA31006F617230 (PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m10D87C6E0708CA912BBB02555BF7D0FBC5D7A2B3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Resources_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m496A3B1B60A28F5E0397043974B848C9157B625A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	{
		// GameObject obj = null;
		V_0 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL;
		// if (poolDic.ContainsKey(name) && poolDic[name].Count > 0)
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_0 = __this->___poolDic_1;
		String_t* L_1 = ___0_name;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F(L_0, L_1, Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_004b;
		}
	}
	{
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_3 = __this->___poolDic_1;
		String_t* L_4 = ___0_name;
		NullCheck(L_3);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_5;
		L_5 = Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D(L_3, L_4, Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		NullCheck(L_5);
		int32_t L_6;
		L_6 = List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_inline(L_5, List_1_get_Count_m4C37ED2D928D63B80F55AF434730C2D64EEB9F22_RuntimeMethod_var);
		if ((((int32_t)L_6) <= ((int32_t)0)))
		{
			goto IL_004b;
		}
	}
	{
		// obj = poolDic[name][0];
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_7 = __this->___poolDic_1;
		String_t* L_8 = ___0_name;
		NullCheck(L_7);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_9;
		L_9 = Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D(L_7, L_8, Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		NullCheck(L_9);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_10;
		L_10 = List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979(L_9, 0, List_1_get_Item_mE8DBE527F24D9CFED839C34216C475B716169979_RuntimeMethod_var);
		V_0 = L_10;
		// poolDic[name].RemoveAt(0);
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_11 = __this->___poolDic_1;
		String_t* L_12 = ___0_name;
		NullCheck(L_11);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_13;
		L_13 = Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D(L_11, L_12, Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		NullCheck(L_13);
		List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260(L_13, 0, List_1_RemoveAt_m3196E18C5CF157CAC58991FACEB9DFD441702260_RuntimeMethod_var);
		goto IL_005e;
	}

IL_004b:
	{
		// obj = GameObject.Instantiate(Resources.Load<GameObject>(name));
		String_t* L_14 = ___0_name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_15;
		L_15 = Resources_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m496A3B1B60A28F5E0397043974B848C9157B625A(L_14, Resources_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m496A3B1B60A28F5E0397043974B848C9157B625A_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_16;
		L_16 = Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m10D87C6E0708CA912BBB02555BF7D0FBC5D7A2B3(L_15, Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m10D87C6E0708CA912BBB02555BF7D0FBC5D7A2B3_RuntimeMethod_var);
		V_0 = L_16;
		// obj.name = name;//???????????????????????????????clone????????
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_17 = V_0;
		String_t* L_18 = ___0_name;
		NullCheck(L_17);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47(L_17, L_18, NULL);
	}

IL_005e:
	{
		// obj.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_19 = V_0;
		NullCheck(L_19);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_19, (bool)1, NULL);
		// return obj;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_20 = V_0;
		return L_20;
	}
}
// System.Void PoolManage::PushObj(System.String,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolManage_PushObj_m286E690E6AF2C1F27094BE6D1428BF8DCEBA4DEE (PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266* __this, String_t* ___0_name, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___1_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m262241C63CA5FD4C4C40338008DD2097E94E6222_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// obj.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___1_obj;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// if (poolDic.ContainsKey(name))
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_1 = __this->___poolDic_1;
		String_t* L_2 = ___0_name;
		NullCheck(L_1);
		bool L_3;
		L_3 = Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F(L_1, L_2, Dictionary_2_ContainsKey_m1E9457332A24F770318282A5432DD865A245171F_RuntimeMethod_var);
		if (!L_3)
		{
			goto IL_0028;
		}
	}
	{
		// poolDic[name].Add(obj);
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_4 = __this->___poolDic_1;
		String_t* L_5 = ___0_name;
		NullCheck(L_4);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_6;
		L_6 = Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D(L_4, L_5, Dictionary_2_get_Item_mD66D768483F2D031BDEB38356D2441BECBEB4A7D_RuntimeMethod_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_7 = ___1_obj;
		NullCheck(L_6);
		List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline(L_6, L_7, List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		return;
	}

IL_0028:
	{
		// poolDic.Add(name, new List<GameObject>() { obj });
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_8 = __this->___poolDic_1;
		String_t* L_9 = ___0_name;
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_10 = (List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B*)il2cpp_codegen_object_new(List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC(L_10, List_1__ctor_m447372C1EF7141193B93090A77395B786C72C7BC_RuntimeMethod_var);
		List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* L_11 = L_10;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_12 = ___1_obj;
		NullCheck(L_11);
		List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_inline(L_11, L_12, List_1_Add_m43FBF207375C6E06B8C45ECE614F9B8008FB686E_RuntimeMethod_var);
		NullCheck(L_8);
		Dictionary_2_Add_m262241C63CA5FD4C4C40338008DD2097E94E6222(L_8, L_9, L_11, Dictionary_2_Add_m262241C63CA5FD4C4C40338008DD2097E94E6222_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void PoolManage::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PoolManage__ctor_mD7D02760C539B49CD63AA77323AC3099C1D5CA06 (PoolManage_tB1FA0DC9B6DC3E3C9ABD2777424450C99CC4E266* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mF24449044241FBE79F9117BCEFA3220A9B495B53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mC3BBDDAFE2FBCB7710787DE56899D4E6BCD9C0A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public Dictionary<string, List<GameObject>> poolDic = new Dictionary<string, List<GameObject>>();
		Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84* L_0 = (Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84*)il2cpp_codegen_object_new(Dictionary_2_t26D5965FC9C07EF9DA22ADFD28E0A82DDF6E5D84_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mC3BBDDAFE2FBCB7710787DE56899D4E6BCD9C0A2(L_0, Dictionary_2__ctor_mC3BBDDAFE2FBCB7710787DE56899D4E6BCD9C0A2_RuntimeMethod_var);
		__this->___poolDic_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___poolDic_1), (void*)L_0);
		BaseManager_1__ctor_mF24449044241FBE79F9117BCEFA3220A9B495B53(__this, BaseManager_1__ctor_mF24449044241FBE79F9117BCEFA3220A9B495B53_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ResMgr::ResourcesLoad()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResMgr_ResourcesLoad_m90CBC4A0DACB7CDFC691DF7C37C125DCCE46F589 (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// m_res = new Hashtable();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D*)il2cpp_codegen_object_new(Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D(L_0, NULL);
		__this->___m_res_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_res_1), (void*)L_0);
		// }
		return;
	}
}
// System.Void ResMgr::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResMgr_Dispose_mFFBB367DF336751D70F5B64D81228A803A3257F9 (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Dispose_mA0466D2F6A65CDCB41846E8C8A5AAF739E38CA53_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// base.Dispose();
		BaseManager_1_Dispose_mA0466D2F6A65CDCB41846E8C8A5AAF739E38CA53(__this, BaseManager_1_Dispose_mA0466D2F6A65CDCB41846E8C8A5AAF739E38CA53_RuntimeMethod_var);
		// m_res.Clear();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = __this->___m_res_1;
		NullCheck(L_0);
		VirtualActionInvoker0::Invoke(16 /* System.Void System.Collections.Hashtable::Clear() */, L_0);
		// Resources.UnloadUnusedAssets();
		AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* L_1;
		L_1 = Resources_UnloadUnusedAssets_m4003CD3EBC3AC2738DE9F2960D5BC45818C1F12B(NULL);
		// }
		return;
	}
}
// System.Void ResMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResMgr__ctor_m27FD38B656451111569E7E30675ABFC386FD1F8C (ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m12855CB17B210C30B34A51A5F46133DC89EC1143_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		BaseManager_1__ctor_m12855CB17B210C30B34A51A5F46133DC89EC1143(__this, BaseManager_1__ctor_m12855CB17B210C30B34A51A5F46133DC89EC1143_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.IEnumerator ResManage::WWWLoad(System.String,System.Action`1<UnityEngine.WWW>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ResManage_WWWLoad_mDF88A9E0EAD196F5B0E13385515BA7DBE4EBA048 (String_t* ___0_url, Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* L_0 = (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C*)il2cpp_codegen_object_new(U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CWWWLoadU3Ed__3__ctor_m1ED9A98955F2F523E6A11F1AD9F1BFD6AD0B9C8D(L_0, 0, NULL);
		U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* L_1 = L_0;
		String_t* L_2 = ___0_url;
		NullCheck(L_1);
		L_1->___url_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___url_2), (void*)L_2);
		U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* L_3 = L_1;
		Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF* L_4 = ___1_callback;
		NullCheck(L_3);
		L_3->___callback_3 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&L_3->___callback_3), (void*)L_4);
		return L_3;
	}
}
// System.Void ResManage::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResManage__ctor_m7E75B8459EBD5CD30C6E9F7E8A832B8E5AE192CB (ResManage_t5FAD4C5CBE0C758E708AF91991FD5E103F61E127* __this, const RuntimeMethod* method) 
{
	{
		ResourcesLoadingMode__ctor_mFBEFA8507463700AC45710EE43B394FCDFE40CBD(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ResManage/<WWWLoad>d__3::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CWWWLoadU3Ed__3__ctor_m1ED9A98955F2F523E6A11F1AD9F1BFD6AD0B9C8D (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void ResManage/<WWWLoad>d__3::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CWWWLoadU3Ed__3_System_IDisposable_Dispose_m4D731372A38FD0F762F6E0EC65BE3E6DCA7EC807 (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean ResManage/<WWWLoad>d__3::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CWWWLoadU3Ed__3_MoveNext_mFE1BD318F8D0B8ED84FBCF9389A3F355F9C40527 (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6AEF201C57685514EF3E2DA0F18AE2E224BEAD5D);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		int32_t L_1 = V_0;
		switch (L_1)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_0052;
			}
			case 2:
			{
				goto IL_007a;
			}
		}
	}
	{
		return (bool)0;
	}

IL_001b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// Debug.Log("----WWW????----");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(_stringLiteral6AEF201C57685514EF3E2DA0F18AE2E224BEAD5D, NULL);
		// WWW www = new WWW(url);
		String_t* L_2 = __this->___url_2;
		WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* L_3 = (WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB*)il2cpp_codegen_object_new(WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		WWW__ctor_m5D29D83E9EE0925ED8252347CE24EC236401503D(L_3, L_2, NULL);
		__this->___U3CwwwU3E5__2_4 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CwwwU3E5__2_4), (void*)L_3);
		// yield return www;
		WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* L_4 = __this->___U3CwwwU3E5__2_4;
		__this->___U3CU3E2__current_1 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_4);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0052:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// callback.Invoke(www);
		Action_1_t41E8AA4E16E872666DF7EC1FF7E2BE87D48EA5BF* L_5 = __this->___callback_3;
		WWW_tEADA9A43B98FC277E498F8E3206A3B8C4E5AF3FB* L_6 = __this->___U3CwwwU3E5__2_4;
		NullCheck(L_5);
		Action_1_Invoke_mD3170EC156395DBCCB2DC1491C5988F3CB2FEB5A_inline(L_5, L_6, NULL);
		// yield return null;
		__this->___U3CU3E2__current_1 = NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)NULL);
		__this->___U3CU3E1__state_0 = 2;
		return (bool)1;
	}

IL_007a:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// }
		return (bool)0;
	}
}
// System.Object ResManage/<WWWLoad>d__3::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CWWWLoadU3Ed__3_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m6625841E7B56C1AD1CB773067AAA077B7FCADD44 (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void ResManage/<WWWLoad>d__3::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CWWWLoadU3Ed__3_System_Collections_IEnumerator_Reset_mA2FEBCB5274E7C74F23470B61C0ECBE9C17CE8DA (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CWWWLoadU3Ed__3_System_Collections_IEnumerator_Reset_mA2FEBCB5274E7C74F23470B61C0ECBE9C17CE8DA_RuntimeMethod_var)));
	}
}
// System.Object ResManage/<WWWLoad>d__3::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CWWWLoadU3Ed__3_System_Collections_IEnumerator_get_Current_m955C04891D7BCD0EA016759C16D6BA0CBA00131D (U3CWWWLoadU3Ed__3_tA6A479233DC731064B6F40BBC4018128169B5F5C* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ScenesMgr::LoadScene(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ScenesMgr_LoadScene_m259C89283624320782690DAFBA6AEC1AC5F36225 (ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_fun, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// SceneManager.LoadScene(name);
		String_t* L_0 = ___0_name;
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(L_0, NULL);
		// fun();
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_1 = ___1_fun;
		NullCheck(L_1);
		UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline(L_1, NULL);
		// }
		return;
	}
}
// System.Void ScenesMgr::LoadSceneAsyn(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ScenesMgr_LoadSceneAsyn_m3928A99ED10A298C357B2CA1C7D2BBAA62A386CD (ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_fun, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// MonoMgr.Getinstance().StartCoroutine(ReallyLoadSceneAsyn(name, fun));
		MonoMgr_tC185BA83134D91972E6D265795900BFB93499B47* L_0;
		L_0 = BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A(BaseManager_1_Getinstance_m8D271F4A79D69C334B6BDF32FE92AE8DF405266A_RuntimeMethod_var);
		String_t* L_1 = ___0_name;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_2 = ___1_fun;
		RuntimeObject* L_3;
		L_3 = ScenesMgr_ReallyLoadSceneAsyn_mCFA56D1928B38BC5EFA4C026F297400E231E7A26(__this, L_1, L_2, NULL);
		NullCheck(L_0);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_4;
		L_4 = MonoMgr_StartCoroutine_m1B651E11C49C987BA6649A89284AE7FBBF081F2B(L_0, L_3, NULL);
		// }
		return;
	}
}
// System.Collections.IEnumerator ScenesMgr::ReallyLoadSceneAsyn(System.String,UnityEngine.Events.UnityAction)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ScenesMgr_ReallyLoadSceneAsyn_mCFA56D1928B38BC5EFA4C026F297400E231E7A26 (ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* __this, String_t* ___0_name, UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___1_fun, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* L_0 = (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A*)il2cpp_codegen_object_new(U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CReallyLoadSceneAsynU3Ed__2__ctor_m76E9A84E1DDFB502D080BB45D52E3C2C80FDDA55(L_0, 0, NULL);
		U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* L_1 = L_0;
		String_t* L_2 = ___0_name;
		NullCheck(L_1);
		L_1->___name_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___name_2), (void*)L_2);
		U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* L_3 = L_1;
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_4 = ___1_fun;
		NullCheck(L_3);
		L_3->___fun_3 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&L_3->___fun_3), (void*)L_4);
		return L_3;
	}
}
// System.Void ScenesMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ScenesMgr__ctor_m6F784989D5F6266868988DFE6FF5F07411DB0D5F (ScenesMgr_t0D9DA8C71E96121043793C1A51B9B8906973A07F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m281F94215DC637D51B8209FC887A679AB62DBF72_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		BaseManager_1__ctor_m281F94215DC637D51B8209FC887A679AB62DBF72(__this, BaseManager_1__ctor_m281F94215DC637D51B8209FC887A679AB62DBF72_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ScenesMgr/<ReallyLoadSceneAsyn>d__2::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CReallyLoadSceneAsynU3Ed__2__ctor_m76E9A84E1DDFB502D080BB45D52E3C2C80FDDA55 (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void ScenesMgr/<ReallyLoadSceneAsyn>d__2::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CReallyLoadSceneAsynU3Ed__2_System_IDisposable_Dispose_m63E825D68A926073BD78647783D51A9FA3BD97BA (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean ScenesMgr/<ReallyLoadSceneAsyn>d__2::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CReallyLoadSceneAsynU3Ed__2_MoveNext_m55FB3EEDF835F9D1BE11DB6508364CDA16C77F60 (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF7ABB51D46C7E6D807C6F4DEB4C79449E27350C0);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if (!L_1)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0063;
		}
	}
	{
		return (bool)0;
	}

IL_0010:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// AsyncOperation ao = SceneManager.LoadSceneAsync(name);
		String_t* L_3 = __this->___name_2;
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* L_4;
		L_4 = SceneManager_LoadSceneAsync_m84D316B1993A4E69F9E8CDE30531687B701F9300(L_3, NULL);
		__this->___U3CaoU3E5__2_4 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CaoU3E5__2_4), (void*)L_4);
		goto IL_006a;
	}

IL_002a:
	{
		// EventCenter.Getinstance().EventTrigger("??????????", ao.progress);
		EventCenter_tD18A89D29718B418443DB34E09FC8127E6FB2170* L_5;
		L_5 = BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53(BaseManager_1_Getinstance_m930CD3DF8D0A1281E19FC78AC4507FB314A2EA53_RuntimeMethod_var);
		AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* L_6 = __this->___U3CaoU3E5__2_4;
		NullCheck(L_6);
		float L_7;
		L_7 = AsyncOperation_get_progress_mF3B2837C1A5DDF3C2F7A3BA1E449DD4C71C632EE(L_6, NULL);
		NullCheck(L_5);
		EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520(L_5, _stringLiteralF7ABB51D46C7E6D807C6F4DEB4C79449E27350C0, L_7, EventCenter_EventTrigger_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m598E8DB0E46A3C35A95DF4CF602042731C431520_RuntimeMethod_var);
		// yield return ao.progress;
		AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* L_8 = __this->___U3CaoU3E5__2_4;
		NullCheck(L_8);
		float L_9;
		L_9 = AsyncOperation_get_progress_mF3B2837C1A5DDF3C2F7A3BA1E449DD4C71C632EE(L_8, NULL);
		float L_10 = L_9;
		RuntimeObject* L_11 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_10);
		__this->___U3CU3E2__current_1 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_11);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0063:
	{
		__this->___U3CU3E1__state_0 = (-1);
	}

IL_006a:
	{
		// while (!ao.isDone)
		AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* L_12 = __this->___U3CaoU3E5__2_4;
		NullCheck(L_12);
		bool L_13;
		L_13 = AsyncOperation_get_isDone_m68A0682777E2132FC033182E9F50303566AA354D(L_12, NULL);
		if (!L_13)
		{
			goto IL_002a;
		}
	}
	{
		// fun();
		UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* L_14 = __this->___fun_3;
		NullCheck(L_14);
		UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline(L_14, NULL);
		// }
		return (bool)0;
	}
}
// System.Object ScenesMgr/<ReallyLoadSceneAsyn>d__2::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CReallyLoadSceneAsynU3Ed__2_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m8EBE64766FB290FCED3E23DA31F7534823C66C65 (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void ScenesMgr/<ReallyLoadSceneAsyn>d__2::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CReallyLoadSceneAsynU3Ed__2_System_Collections_IEnumerator_Reset_m24991A1FD836CB9F9CC969577E9B492B82F5D1F5 (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CReallyLoadSceneAsynU3Ed__2_System_Collections_IEnumerator_Reset_m24991A1FD836CB9F9CC969577E9B492B82F5D1F5_RuntimeMethod_var)));
	}
}
// System.Object ScenesMgr/<ReallyLoadSceneAsyn>d__2::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CReallyLoadSceneAsynU3Ed__2_System_Collections_IEnumerator_get_Current_m42675D5201DEF5D2E4D9C6D19EAC0D7F9BF7675D (U3CReallyLoadSceneAsynU3Ed__2_tD8F41E8F871B02B8B132E6B4A83EDBAD6506611A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TextureMgr::init()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TextureMgr_init_mBABD83A8E28A56B2C8264FEBD99D82EC8D8BDD01 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mFAF8880680AB14AC23BE7F389E98862841A59CE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m_pAtlasDic == null)
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_0 = __this->___m_pAtlasDic_1;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// m_pAtlasDic = new Dictionary<string, Object[]>();
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_1 = (Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19*)il2cpp_codegen_object_new(Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Dictionary_2__ctor_mFAF8880680AB14AC23BE7F389E98862841A59CE9(L_1, Dictionary_2__ctor_mFAF8880680AB14AC23BE7F389E98862841A59CE9_RuntimeMethod_var);
		__this->___m_pAtlasDic_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_pAtlasDic_1), (void*)L_1);
	}

IL_0013:
	{
		// }
		return;
	}
}
// System.Void TextureMgr::DeleteAtlas(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TextureMgr_DeleteAtlas_mF6405FD92884C4C4EEE12242BA6F0D775C9C19A8 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, String_t* ___0__spriteAtlasPath, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_m1F5269D68341155CEFF355916ED98C36FB157D29_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m_pAtlasDic.ContainsKey(_spriteAtlasPath))
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_0 = __this->___m_pAtlasDic_1;
		String_t* L_1 = ___0__spriteAtlasPath;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74(L_0, L_1, Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_001b;
		}
	}
	{
		// m_pAtlasDic.Remove(_spriteAtlasPath);  //Remove?Dictionary???????
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_3 = __this->___m_pAtlasDic_1;
		String_t* L_4 = ___0__spriteAtlasPath;
		NullCheck(L_3);
		bool L_5;
		L_5 = Dictionary_2_Remove_m1F5269D68341155CEFF355916ED98C36FB157D29(L_3, L_4, Dictionary_2_Remove_m1F5269D68341155CEFF355916ED98C36FB157D29_RuntimeMethod_var);
	}

IL_001b:
	{
		// }
		return;
	}
}
// System.Void TextureMgr::LoadResAtlas(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TextureMgr_LoadResAtlas_mB523FC3134E75EC5ED1B53D9225A53F780653322 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, String_t* ___0__spriteAtlasPath, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD16E68047D3CA19D8302E86499BBAAFB39246C53);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_0 = NULL;
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* G_B1_0 = NULL;
	String_t* G_B1_1 = NULL;
	String_t* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	{
		// Debug.Log("All:::" + Resources.LoadAll(_spriteAtlasPath));
		String_t* L_0 = ___0__spriteAtlasPath;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_1;
		L_1 = Resources_LoadAll_m3C9742F2FA0ADB6F8C057527D0588F5BDCF8CF56(L_0, NULL);
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_2 = L_1;
		G_B1_0 = L_2;
		G_B1_1 = _stringLiteralD16E68047D3CA19D8302E86499BBAAFB39246C53;
		if (L_2)
		{
			G_B2_0 = L_2;
			G_B2_1 = _stringLiteralD16E68047D3CA19D8302E86499BBAAFB39246C53;
			goto IL_0012;
		}
	}
	{
		G_B3_0 = ((String_t*)(NULL));
		G_B3_1 = G_B1_1;
		goto IL_0017;
	}

IL_0012:
	{
		NullCheck((RuntimeObject*)G_B2_0);
		String_t* L_3;
		L_3 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, (RuntimeObject*)G_B2_0);
		G_B3_0 = L_3;
		G_B3_1 = G_B2_1;
	}

IL_0017:
	{
		String_t* L_4;
		L_4 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B3_1, G_B3_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_4, NULL);
		// Object[] _atlas = Resources.LoadAll(_spriteAtlasPath);
		String_t* L_5 = ___0__spriteAtlasPath;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_6;
		L_6 = Resources_LoadAll_m3C9742F2FA0ADB6F8C057527D0588F5BDCF8CF56(L_5, NULL);
		V_0 = L_6;
		// if (!m_pAtlasDic.ContainsKey(_spriteAtlasPath)) { m_pAtlasDic.Add(_spriteAtlasPath, _atlas); }
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_7 = __this->___m_pAtlasDic_1;
		String_t* L_8 = ___0__spriteAtlasPath;
		NullCheck(L_7);
		bool L_9;
		L_9 = Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74(L_7, L_8, Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		if (L_9)
		{
			goto IL_0043;
		}
	}
	{
		// if (!m_pAtlasDic.ContainsKey(_spriteAtlasPath)) { m_pAtlasDic.Add(_spriteAtlasPath, _atlas); }
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_10 = __this->___m_pAtlasDic_1;
		String_t* L_11 = ___0__spriteAtlasPath;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_12 = V_0;
		NullCheck(L_10);
		Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2(L_10, L_11, L_12, Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2_RuntimeMethod_var);
	}

IL_0043:
	{
		// }
		return;
	}
}
// UnityEngine.Sprite TextureMgr::LoadResAtlasSprite(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* TextureMgr_LoadResAtlasSprite_mC96298BEECFE620DA9330868D7D729380BB969E6 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, String_t* ___0__spriteAtlasPath, String_t* ___1__spriteName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* V_0 = NULL;
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_1 = NULL;
	{
		// Sprite _sprite = FindSpriteFormBuffer(_spriteAtlasPath, _spriteName);
		String_t* L_0 = ___0__spriteAtlasPath;
		String_t* L_1 = ___1__spriteName;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_2;
		L_2 = TextureMgr_FindSpriteFormBuffer_m1890DCADE0F513543E47712C4366A0FE8F92BB56(__this, L_0, L_1, NULL);
		V_0 = L_2;
		// if (_sprite == null) {
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_3 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_3, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_4)
		{
			goto IL_003d;
		}
	}
	{
		// Object[] _atlas = Resources.LoadAll(_spriteAtlasPath);
		String_t* L_5 = ___0__spriteAtlasPath;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_6;
		L_6 = Resources_LoadAll_m3C9742F2FA0ADB6F8C057527D0588F5BDCF8CF56(L_5, NULL);
		V_1 = L_6;
		// if(!m_pAtlasDic.ContainsKey(_spriteAtlasPath)) {m_pAtlasDic.Add (_spriteAtlasPath,_atlas); }
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_7 = __this->___m_pAtlasDic_1;
		String_t* L_8 = ___0__spriteAtlasPath;
		NullCheck(L_7);
		bool L_9;
		L_9 = Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74(L_7, L_8, Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		if (L_9)
		{
			goto IL_0034;
		}
	}
	{
		// if(!m_pAtlasDic.ContainsKey(_spriteAtlasPath)) {m_pAtlasDic.Add (_spriteAtlasPath,_atlas); }
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_10 = __this->___m_pAtlasDic_1;
		String_t* L_11 = ___0__spriteAtlasPath;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_12 = V_1;
		NullCheck(L_10);
		Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2(L_10, L_11, L_12, Dictionary_2_Add_mCA81B04A82CF0685513DEECF7AF54582CF6994B2_RuntimeMethod_var);
	}

IL_0034:
	{
		// _sprite = SpriteFormAtlas (_atlas,_spriteName);  //SpriteFormAtlas??????????
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_13 = V_1;
		String_t* L_14 = ___1__spriteName;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_15;
		L_15 = TextureMgr_SpriteFormAtlas_mB65341B2D4505ABF3F52ABE987CF39BA24F809EE(__this, L_13, L_14, NULL);
		V_0 = L_15;
	}

IL_003d:
	{
		// return _sprite;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_16 = V_0;
		return L_16;
	}
}
// UnityEngine.Sprite TextureMgr::FindSpriteFormBuffer(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* TextureMgr_FindSpriteFormBuffer_m1890DCADE0F513543E47712C4366A0FE8F92BB56 (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, String_t* ___0__spriteAtlasPath, String_t* ___1__spriteName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mBA8590162AAF64A9FEA05B610BCDCB7904D55587_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_0 = NULL;
	{
		// if (m_pAtlasDic.ContainsKey(_spriteAtlasPath))
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_0 = __this->___m_pAtlasDic_1;
		String_t* L_1 = ___0__spriteAtlasPath;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74(L_0, L_1, Dictionary_2_ContainsKey_m34D9EE7E8032C71C39BACEC888D521BF1CF1DD74_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0024;
		}
	}
	{
		// Object[] _atlas = m_pAtlasDic[_spriteAtlasPath]; //?m_pAtlasDic???????????
		Dictionary_2_t1B4217B7C2936D48F22E99FFB8255916F5B09A19* L_3 = __this->___m_pAtlasDic_1;
		String_t* L_4 = ___0__spriteAtlasPath;
		NullCheck(L_3);
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_5;
		L_5 = Dictionary_2_get_Item_mBA8590162AAF64A9FEA05B610BCDCB7904D55587(L_3, L_4, Dictionary_2_get_Item_mBA8590162AAF64A9FEA05B610BCDCB7904D55587_RuntimeMethod_var);
		V_0 = L_5;
		// Sprite _sprite = SpriteFormAtlas(_atlas, _spriteName);  //?m_pAtlasDic????
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_6 = V_0;
		String_t* L_7 = ___1__spriteName;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_8;
		L_8 = TextureMgr_SpriteFormAtlas_mB65341B2D4505ABF3F52ABE987CF39BA24F809EE(__this, L_6, L_7, NULL);
		// return _sprite;
		return L_8;
	}

IL_0024:
	{
		// return null;
		return (Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99*)NULL;
	}
}
// UnityEngine.Sprite TextureMgr::SpriteFormAtlas(UnityEngine.Object[],System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* TextureMgr_SpriteFormAtlas_mB65341B2D4505ABF3F52ABE987CF39BA24F809EE (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* ___0__atlas, String_t* ___1__spriteName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2AD9F8D8C3A372CA0039306F13BEDA0B460207C8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD620A361DDE79216C95A8EB1682325D49CFFEB33);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// for (int i = 0; i < _atlas.Length; i++)
		V_0 = 0;
		goto IL_0021;
	}

IL_0004:
	{
		// if (_atlas[i].name == _spriteName)
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_0 = ___0__atlas;
		int32_t L_1 = V_0;
		NullCheck(L_0);
		int32_t L_2 = L_1;
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		String_t* L_4;
		L_4 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_3, NULL);
		String_t* L_5 = ___1__spriteName;
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, L_5, NULL);
		if (!L_6)
		{
			goto IL_001d;
		}
	}
	{
		// return (Sprite)_atlas[i];
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_7 = ___0__atlas;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return ((Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99*)CastclassSealed((RuntimeObject*)L_10, Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99_il2cpp_TypeInfo_var));
	}

IL_001d:
	{
		// for (int i = 0; i < _atlas.Length; i++)
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0021:
	{
		// for (int i = 0; i < _atlas.Length; i++)
		int32_t L_12 = V_0;
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_13 = ___0__atlas;
		NullCheck(L_13);
		if ((((int32_t)L_12) < ((int32_t)((int32_t)(((RuntimeArray*)L_13)->max_length)))))
		{
			goto IL_0004;
		}
	}
	{
		// Debug.LogWarning("sprite:" + _spriteName + ";undefinde in atlas");  //????return
		String_t* L_14 = ___1__spriteName;
		String_t* L_15;
		L_15 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteral2AD9F8D8C3A372CA0039306F13BEDA0B460207C8, L_14, _stringLiteralD620A361DDE79216C95A8EB1682325D49CFFEB33, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_15, NULL);
		// return null;
		return (Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99*)NULL;
	}
}
// System.Void TextureMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TextureMgr__ctor_mD41419A9E8919E65458569ACD5E071E894B37EEE (TextureMgr_t3BF6AC0A13A820B135DDA67577415B32FD1AC901* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mDC5FD6061CABB05CC105C36E9311336DD2BDCF0C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		BaseManager_1__ctor_mDC5FD6061CABB05CC105C36E9311336DD2BDCF0C(__this, BaseManager_1__ctor_mDC5FD6061CABB05CC105C36E9311336DD2BDCF0C_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TimerNode::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerNode__ctor_mBF40DD1358D6BD9044E38145D03FF7023C2EE7BF (TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TimerMgr::Init()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerMgr_Init_m5E0931223C8CB5175766AD2F4D35F72674BB8254 (TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mA1D9EB14DD67356C94A0C1717D80F18979B839C0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// timers = new Dictionary<int, TimerNode>();
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_0 = (Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF*)il2cpp_codegen_object_new(Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mA1D9EB14DD67356C94A0C1717D80F18979B839C0(L_0, Dictionary_2__ctor_mA1D9EB14DD67356C94A0C1717D80F18979B839C0_RuntimeMethod_var);
		__this->___timers_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___timers_1), (void*)L_0);
		// autoIncId = 1;
		__this->___autoIncId_4 = 1;
		// removeTimers = new List<TimerNode>();
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_1 = (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*)il2cpp_codegen_object_new(List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64(L_1, List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64_RuntimeMethod_var);
		__this->___removeTimers_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___removeTimers_2), (void*)L_1);
		// newAddTimers = new List<TimerNode>();
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_2 = (List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5*)il2cpp_codegen_object_new(List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64(L_2, List_1__ctor_m8FEE673B9FDF5EEEB69D83C3269058AB4EA12C64_RuntimeMethod_var);
		__this->___newAddTimers_3 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___newAddTimers_3), (void*)L_2);
		// }
		return;
	}
}
// System.Int32 TimerMgr::Schedule(TimerMgr/TimerHandler,System.Single,System.Single,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TimerMgr_Schedule_mD345BA2CEED65860EAD64ADAF14D7C10A32F66C9 (TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* __this, TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* ___0_methodName, float ___1_time, float ___2_repeatRate, int32_t ___3_repeat, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* V_0 = NULL;
	{
		// TimerNode timer = new TimerNode();
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_0 = (TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7*)il2cpp_codegen_object_new(TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		TimerNode__ctor_mBF40DD1358D6BD9044E38145D03FF7023C2EE7BF(L_0, NULL);
		V_0 = L_0;
		// timer.callback = methodName;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_1 = V_0;
		TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* L_2 = ___0_methodName;
		NullCheck(L_1);
		L_1->___callback_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___callback_0), (void*)L_2);
		// timer.repeat = repeat;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_3 = V_0;
		int32_t L_4 = ___3_repeat;
		NullCheck(L_3);
		L_3->___repeat_3 = L_4;
		// timer.repeatRate = repeatRate;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_5 = V_0;
		float L_6 = ___2_repeatRate;
		NullCheck(L_5);
		L_5->___repeatRate_1 = L_6;
		// timer.time = time;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_7 = V_0;
		float L_8 = ___1_time;
		NullCheck(L_7);
		L_7->___time_2 = L_8;
		// timer.passedTime = timer.repeatRate; // ????
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_9 = V_0;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_10 = V_0;
		NullCheck(L_10);
		float L_11 = L_10->___repeatRate_1;
		NullCheck(L_9);
		L_9->___passedTime_4 = L_11;
		// timer.isRemoved = false;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_12 = V_0;
		NullCheck(L_12);
		L_12->___isRemoved_5 = (bool)0;
		// timer.timerId = autoIncId;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_13 = V_0;
		int32_t L_14 = __this->___autoIncId_4;
		NullCheck(L_13);
		L_13->___timerId_6 = L_14;
		// autoIncId++;
		int32_t L_15 = __this->___autoIncId_4;
		__this->___autoIncId_4 = ((int32_t)il2cpp_codegen_add(L_15, 1));
		// newAddTimers.Add(timer); // ????????
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_16 = __this->___newAddTimers_3;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_17 = V_0;
		NullCheck(L_16);
		List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_inline(L_16, L_17, List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var);
		// return timer.timerId;
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_18 = V_0;
		NullCheck(L_18);
		int32_t L_19 = L_18->___timerId_6;
		return L_19;
	}
}
// System.Void TimerMgr::Unschedule(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerMgr_Unschedule_m7C76695548AD03313086A0553268C004857D5090 (TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* __this, int32_t ___0_timerId, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_m1711AF6E4992D16A259079D27B3B190A2E0641D3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m779DD6A6BA1E9FA43761E654977AE8C9CC45FF34_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!timers.ContainsKey(timerId))
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_0 = __this->___timers_1;
		int32_t L_1 = ___0_timerId;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m1711AF6E4992D16A259079D27B3B190A2E0641D3(L_0, L_1, Dictionary_2_ContainsKey_m1711AF6E4992D16A259079D27B3B190A2E0641D3_RuntimeMethod_var);
		if (L_2)
		{
			goto IL_000f;
		}
	}
	{
		// return;
		return;
	}

IL_000f:
	{
		// TimerNode timer = timers[timerId];
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_3 = __this->___timers_1;
		int32_t L_4 = ___0_timerId;
		NullCheck(L_3);
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_5;
		L_5 = Dictionary_2_get_Item_m779DD6A6BA1E9FA43761E654977AE8C9CC45FF34(L_3, L_4, Dictionary_2_get_Item_m779DD6A6BA1E9FA43761E654977AE8C9CC45FF34_RuntimeMethod_var);
		// timer.isRemoved = true; // ?????????
		NullCheck(L_5);
		L_5->___isRemoved_5 = (bool)1;
		// }
		return;
	}
}
// System.Void TimerMgr::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerMgr_Update_mCFCB74F8A48871BEF527A84D1EB6D9979C2A6413 (TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m9AFDA112B11C0CD915081B9B2DF3B78C84CD82E8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_m37200A4980CCA1989CFE0A913D65F5B9D8E507D3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Values_m88D0B7D51A606222E4BBAFF146B77772E5491B7E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_mA4BD3457EF4189DB8017D964A865BF98CE30DEC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m8172A0F32B0FD2CB250B2F7E9B1B4ED285A0E4CF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m92C769426ADE52700E4F8E40760D6F8FAED469ED_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ValueCollection_GetEnumerator_mA8242DA37C7181A80FCEEB7535CA464991FC2C17_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	int32_t V_1 = 0;
	Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934 V_2;
	memset((&V_2), 0, sizeof(V_2));
	TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* V_3 = NULL;
	int32_t V_4 = 0;
	{
		// float dt = Time.deltaTime;
		float L_0;
		L_0 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		V_0 = L_0;
		// for (int i = 0; i < newAddTimers.Count; i++)
		V_1 = 0;
		goto IL_0036;
	}

IL_000a:
	{
		// timers.Add(newAddTimers[i].timerId, newAddTimers[i]);
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_1 = __this->___timers_1;
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_2 = __this->___newAddTimers_3;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_4;
		L_4 = List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E(L_2, L_3, List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E_RuntimeMethod_var);
		NullCheck(L_4);
		int32_t L_5 = L_4->___timerId_6;
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_6 = __this->___newAddTimers_3;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_8;
		L_8 = List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E(L_6, L_7, List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E_RuntimeMethod_var);
		NullCheck(L_1);
		Dictionary_2_Add_m9AFDA112B11C0CD915081B9B2DF3B78C84CD82E8(L_1, L_5, L_8, Dictionary_2_Add_m9AFDA112B11C0CD915081B9B2DF3B78C84CD82E8_RuntimeMethod_var);
		// for (int i = 0; i < newAddTimers.Count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0036:
	{
		// for (int i = 0; i < newAddTimers.Count; i++)
		int32_t L_10 = V_1;
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_11 = __this->___newAddTimers_3;
		NullCheck(L_11);
		int32_t L_12;
		L_12 = List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_inline(L_11, List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_RuntimeMethod_var);
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000a;
		}
	}
	{
		// newAddTimers.Clear();
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_13 = __this->___newAddTimers_3;
		NullCheck(L_13);
		List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_inline(L_13, List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_RuntimeMethod_var);
		// foreach (TimerNode timer in timers.Values)
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_14 = __this->___timers_1;
		NullCheck(L_14);
		ValueCollection_t6E7A45511879A96FBE4E8F7C5C76BC514E81EC97* L_15;
		L_15 = Dictionary_2_get_Values_m88D0B7D51A606222E4BBAFF146B77772E5491B7E(L_14, Dictionary_2_get_Values_m88D0B7D51A606222E4BBAFF146B77772E5491B7E_RuntimeMethod_var);
		NullCheck(L_15);
		Enumerator_t68E5FEB79527905D01FE61CA84AFE24174225934 L_16;
		L_16 = ValueCollection_GetEnumerator_mA8242DA37C7181A80FCEEB7535CA464991FC2C17(L_15, ValueCollection_GetEnumerator_mA8242DA37C7181A80FCEEB7535CA464991FC2C17_RuntimeMethod_var);
		V_2 = L_16;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_010d:
			{// begin finally (depth: 1)
				Enumerator_Dispose_mA4BD3457EF4189DB8017D964A865BF98CE30DEC9((&V_2), Enumerator_Dispose_mA4BD3457EF4189DB8017D964A865BF98CE30DEC9_RuntimeMethod_var);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_00ff_1;
			}

IL_0065_1:
			{
				// foreach (TimerNode timer in timers.Values)
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_17;
				L_17 = Enumerator_get_Current_m92C769426ADE52700E4F8E40760D6F8FAED469ED_inline((&V_2), Enumerator_get_Current_m92C769426ADE52700E4F8E40760D6F8FAED469ED_RuntimeMethod_var);
				V_3 = L_17;
				// if (timer.isRemoved)
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_18 = V_3;
				NullCheck(L_18);
				bool L_19 = L_18->___isRemoved_5;
				if (!L_19)
				{
					goto IL_0083_1;
				}
			}
			{
				// removeTimers.Add(timer);
				List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_20 = __this->___removeTimers_2;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_21 = V_3;
				NullCheck(L_20);
				List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_inline(L_20, L_21, List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var);
				// continue;
				goto IL_00ff_1;
			}

IL_0083_1:
			{
				// timer.passedTime += dt;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_22 = V_3;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_23 = L_22;
				NullCheck(L_23);
				float L_24 = L_23->___passedTime_4;
				float L_25 = V_0;
				NullCheck(L_23);
				L_23->___passedTime_4 = ((float)il2cpp_codegen_add(L_24, L_25));
				// if (timer.passedTime >= (timer.time + timer.repeatRate))
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_26 = V_3;
				NullCheck(L_26);
				float L_27 = L_26->___passedTime_4;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_28 = V_3;
				NullCheck(L_28);
				float L_29 = L_28->___time_2;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_30 = V_3;
				NullCheck(L_30);
				float L_31 = L_30->___repeatRate_1;
				if ((!(((float)L_27) >= ((float)((float)il2cpp_codegen_add(L_29, L_31))))))
				{
					goto IL_00ff_1;
				}
			}
			{
				// timer.callback();
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_32 = V_3;
				NullCheck(L_32);
				TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* L_33 = L_32->___callback_0;
				NullCheck(L_33);
				TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_inline(L_33, NULL);
				// timer.repeat--;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_34 = V_3;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_35 = L_34;
				NullCheck(L_35);
				int32_t L_36 = L_35->___repeat_3;
				NullCheck(L_35);
				L_35->___repeat_3 = ((int32_t)il2cpp_codegen_subtract(L_36, 1));
				// timer.passedTime -= (timer.time + timer.repeatRate);
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_37 = V_3;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_38 = L_37;
				NullCheck(L_38);
				float L_39 = L_38->___passedTime_4;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_40 = V_3;
				NullCheck(L_40);
				float L_41 = L_40->___time_2;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_42 = V_3;
				NullCheck(L_42);
				float L_43 = L_42->___repeatRate_1;
				NullCheck(L_38);
				L_38->___passedTime_4 = ((float)il2cpp_codegen_subtract(L_39, ((float)il2cpp_codegen_add(L_41, L_43))));
				// timer.time = 0;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_44 = V_3;
				NullCheck(L_44);
				L_44->___time_2 = (0.0f);
				// if (timer.repeat == 0)
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_45 = V_3;
				NullCheck(L_45);
				int32_t L_46 = L_45->___repeat_3;
				if (L_46)
				{
					goto IL_00ff_1;
				}
			}
			{
				// timer.isRemoved = true;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_47 = V_3;
				NullCheck(L_47);
				L_47->___isRemoved_5 = (bool)1;
				// removeTimers.Add(timer);
				List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_48 = __this->___removeTimers_2;
				TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_49 = V_3;
				NullCheck(L_48);
				List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_inline(L_48, L_49, List_1_Add_m3EF5AC420BF9011282D07E9A524D8ADFD81A0435_RuntimeMethod_var);
			}

IL_00ff_1:
			{
				// foreach (TimerNode timer in timers.Values)
				bool L_50;
				L_50 = Enumerator_MoveNext_m8172A0F32B0FD2CB250B2F7E9B1B4ED285A0E4CF((&V_2), Enumerator_MoveNext_m8172A0F32B0FD2CB250B2F7E9B1B4ED285A0E4CF_RuntimeMethod_var);
				if (L_50)
				{
					goto IL_0065_1;
				}
			}
			{
				goto IL_011b;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_011b:
	{
		// for (int i = 0; i < removeTimers.Count; i++)
		V_4 = 0;
		goto IL_0144;
	}

IL_0120:
	{
		// timers.Remove(removeTimers[i].timerId);
		Dictionary_2_t22D56EC5C7DC23076BB473DC1B973A52BD459CEF* L_51 = __this->___timers_1;
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_52 = __this->___removeTimers_2;
		int32_t L_53 = V_4;
		NullCheck(L_52);
		TimerNode_tBD77E21AA78453D9788D9C7BEBE437C3E146DFF7* L_54;
		L_54 = List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E(L_52, L_53, List_1_get_Item_m905C19B296F5D9E1EDB00C0A69D0377B763BAB6E_RuntimeMethod_var);
		NullCheck(L_54);
		int32_t L_55 = L_54->___timerId_6;
		NullCheck(L_51);
		bool L_56;
		L_56 = Dictionary_2_Remove_m37200A4980CCA1989CFE0A913D65F5B9D8E507D3(L_51, L_55, Dictionary_2_Remove_m37200A4980CCA1989CFE0A913D65F5B9D8E507D3_RuntimeMethod_var);
		// for (int i = 0; i < removeTimers.Count; i++)
		int32_t L_57 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_0144:
	{
		// for (int i = 0; i < removeTimers.Count; i++)
		int32_t L_58 = V_4;
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_59 = __this->___removeTimers_2;
		NullCheck(L_59);
		int32_t L_60;
		L_60 = List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_inline(L_59, List_1_get_Count_m7BB23A1ABD6602FA8625E4A5ED41BBC341C3661A_RuntimeMethod_var);
		if ((((int32_t)L_58) < ((int32_t)L_60)))
		{
			goto IL_0120;
		}
	}
	{
		// removeTimers.Clear();
		List_1_tB7A2D0AD7A437D26E8E2EA6DC81872FDC923BCE5* L_61 = __this->___removeTimers_2;
		NullCheck(L_61);
		List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_inline(L_61, List_1_Clear_mCC2790CC5DA2F1CF86F4E2FE1C0B29691BE05A75_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void TimerMgr::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerMgr__ctor_m166DBB0BA4FA95FAE4D8B02284213E5DBD4EC7A8 (TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m10373C1881893A2C205BE38BF428C64D736D3F88_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private int autoIncId = 1;//??Timer?????
		__this->___autoIncId_4 = 1;
		BaseManager_1__ctor_m10373C1881893A2C205BE38BF428C64D736D3F88(__this, BaseManager_1__ctor_m10373C1881893A2C205BE38BF428C64D736D3F88_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_Multicast(TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* currentDelegate = reinterpret_cast<TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_OpenInst(TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_OpenStatic(TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_OpenStaticInvoker(TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker0::Invoke(__this->___method_ptr_0, method, NULL);
}
void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_ClosedStaticInvoker(TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker1< RuntimeObject* >::Invoke(__this->___method_ptr_0, method, NULL, __this->___m_target_2);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23 (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)();
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc();

}
// System.Void TimerMgr/TimerHandler::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerHandler__ctor_mA5ABC2156C09EAB4B714BF8ED32CF040FEC9AEF6 (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 0;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_Multicast;
}
// System.Void TimerMgr/TimerHandler::Invoke()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9 (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult TimerMgr/TimerHandler::BeginInvoke(System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TimerHandler_BeginInvoke_m823398EF35E4DF2E20E90C17326A94782CE9CE78 (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___0_callback, RuntimeObject* ___1_object, const RuntimeMethod* method) 
{
	void *__d_args[1] = {0};
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___0_callback, (RuntimeObject*)___1_object);
}
// System.Void TimerMgr/TimerHandler::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimerHandler_EndInvoke_m4C087B9666CBD430A8F5D7F72709425C3FB3C4B8 (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UIManager::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager__ctor_mC9DC2B8984E76F424E73C1860AD4BD3DEBF6573F (UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m77C93A4EE16FCB481F59FCF871382DFB8C142CAA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m8ADA5D11C145B740261CF875F392AF711FE1423C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5DB596466906579C0A69E299AFF6AE1ABC42D9F1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral719F762A86CD14403E2AE40F2B708BA434A967A2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8203E97DE0174CAD29A442EADB89EBE0C1A2ED68);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC4DC1E9A8507E97CD9B7016D8AF01F02FF133A0C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralED1214349048E77894291A17B22CFB3D36649C9D);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	{
		// public Dictionary<string, BasePanel> panelDic = new Dictionary<string, BasePanel>();
		Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* L_0 = (Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294*)il2cpp_codegen_object_new(Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m8ADA5D11C145B740261CF875F392AF711FE1423C(L_0, Dictionary_2__ctor_m8ADA5D11C145B740261CF875F392AF711FE1423C_RuntimeMethod_var);
		__this->___panelDic_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___panelDic_1), (void*)L_0);
		// public UIManager()
		BaseManager_1__ctor_m77C93A4EE16FCB481F59FCF871382DFB8C142CAA(__this, BaseManager_1__ctor_m77C93A4EE16FCB481F59FCF871382DFB8C142CAA_RuntimeMethod_var);
		// GameObject obj = ResMgr.Getinstance().Load<GameObject>("UI/Canvas");
		ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* L_1;
		L_1 = BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC(BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		NullCheck(L_1);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A(L_1, _stringLiteral719F762A86CD14403E2AE40F2B708BA434A967A2, (bool)0, ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A_RuntimeMethod_var);
		V_0 = L_2;
		// canvas = obj.transform as RectTransform;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = V_0;
		NullCheck(L_3);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_4;
		L_4 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_3, NULL);
		__this->___canvas_5 = ((RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5*)IsInstSealed((RuntimeObject*)L_4, RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___canvas_5), (void*)((RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5*)IsInstSealed((RuntimeObject*)L_4, RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5_il2cpp_TypeInfo_var)));
		// GameObject.DontDestroyOnLoad(obj);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_5, NULL);
		// bot = canvas.Find("Layer_Bot");
		RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* L_6 = __this->___canvas_5;
		NullCheck(L_6);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7;
		L_7 = Transform_Find_m3087032B0E1C5B96A2D2C27020BAEAE2DA08F932(L_6, _stringLiteralED1214349048E77894291A17B22CFB3D36649C9D, NULL);
		__this->___bot_2 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___bot_2), (void*)L_7);
		// mid = canvas.Find("Layer_Mid");
		RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* L_8 = __this->___canvas_5;
		NullCheck(L_8);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_9;
		L_9 = Transform_Find_m3087032B0E1C5B96A2D2C27020BAEAE2DA08F932(L_8, _stringLiteral5DB596466906579C0A69E299AFF6AE1ABC42D9F1, NULL);
		__this->___mid_3 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___mid_3), (void*)L_9);
		// top = canvas.Find("Layer_Top");
		RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* L_10 = __this->___canvas_5;
		NullCheck(L_10);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_11;
		L_11 = Transform_Find_m3087032B0E1C5B96A2D2C27020BAEAE2DA08F932(L_10, _stringLiteral8203E97DE0174CAD29A442EADB89EBE0C1A2ED68, NULL);
		__this->___top_4 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___top_4), (void*)L_11);
		// obj = ResMgr.Getinstance().Load<GameObject>("UI/EventSystem");
		ResMgr_tE099D37ABFF91BB4953488432EEEA3086C0B7482* L_12;
		L_12 = BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC(BaseManager_1_Getinstance_m93D643AEC15C72A6AD26FCBBF1B07CC638A90BAC_RuntimeMethod_var);
		NullCheck(L_12);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13;
		L_13 = ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A(L_12, _stringLiteralC4DC1E9A8507E97CD9B7016D8AF01F02FF133A0C, (bool)0, ResMgr_Load_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m9BB91375553163C0C66C765A31D842305BF6034A_RuntimeMethod_var);
		V_0 = L_13;
		// GameObject.DontDestroyOnLoad(obj);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14 = V_0;
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_14, NULL);
		// }
		return;
	}
}
// UnityEngine.Transform UIManager::GetLayerFather(E_UI_Layer)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* UIManager_GetLayerFather_m1B5DC1F36453624F6F196241EE68916D007C4A8F (UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3* __this, int32_t ___0_layer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_layer;
		switch (L_0)
		{
			case 0:
			{
				goto IL_0014;
			}
			case 1:
			{
				goto IL_001b;
			}
			case 2:
			{
				goto IL_0022;
			}
		}
	}
	{
		goto IL_0029;
	}

IL_0014:
	{
		// return this.bot;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_1 = __this->___bot_2;
		return L_1;
	}

IL_001b:
	{
		// return this.mid;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2 = __this->___mid_3;
		return L_2;
	}

IL_0022:
	{
		// return this.top;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_3 = __this->___top_4;
		return L_3;
	}

IL_0029:
	{
		// return null;
		return (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1*)NULL;
	}
}
// System.Void UIManager::HidePanel(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIManager_HidePanel_m2C063BC0772DE015CF17C481813D65E2AA3582C1 (UIManager_t16825A2483574F37D7D47AB939A6FA639678B1F3* __this, String_t* ___0_panelName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_mE7FD7A2EF471213473524B8051F0B27059B3E9F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_mCE9DE052A13E9FF30C3200B08CE80100D8DB09C5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (panelDic.ContainsKey(panelName))
		Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* L_0 = __this->___panelDic_1;
		String_t* L_1 = ___0_panelName;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_mE7FD7A2EF471213473524B8051F0B27059B3E9F8(L_0, L_1, Dictionary_2_ContainsKey_mE7FD7A2EF471213473524B8051F0B27059B3E9F8_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_0042;
		}
	}
	{
		// panelDic[panelName].HideMe();
		Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* L_3 = __this->___panelDic_1;
		String_t* L_4 = ___0_panelName;
		NullCheck(L_3);
		BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* L_5;
		L_5 = Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654(L_3, L_4, Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654_RuntimeMethod_var);
		NullCheck(L_5);
		VirtualActionInvoker0::Invoke(6 /* System.Void BasePanel::HideMe() */, L_5);
		// GameObject.Destroy(panelDic[panelName].gameObject);
		Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* L_6 = __this->___panelDic_1;
		String_t* L_7 = ___0_panelName;
		NullCheck(L_6);
		BasePanel_t45E6B6F84FB7F1567452B6147DF9F230D07B063D* L_8;
		L_8 = Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654(L_6, L_7, Dictionary_2_get_Item_m2B712A053B9D3B9BB0BCE4A0D62B6873D63AC654_RuntimeMethod_var);
		NullCheck(L_8);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_9;
		L_9 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_9, NULL);
		// panelDic.Remove(panelName);
		Dictionary_2_t082C802CE656A9D7899EC95C29892A8642D48294* L_10 = __this->___panelDic_1;
		String_t* L_11 = ___0_panelName;
		NullCheck(L_10);
		bool L_12;
		L_12 = Dictionary_2_Remove_mCE9DE052A13E9FF30C3200B08CE80100D8DB09C5(L_10, L_11, Dictionary_2_Remove_mCE9DE052A13E9FF30C3200B08CE80100D8DB09C5_RuntimeMethod_var);
	}

IL_0042:
	{
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void GameData::AnalyseAjust()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameData_AnalyseAjust_m9F9CE5CD4B8AA2B44DAFF13778FD881E5CB9F8A5 (GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral467E141EA4AD8622B0ACCD7E96619F6FDC12DD21);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8CBC0B20B7980F8F53D0AAAAD321F93E251E1FA1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE9145F1641B02E019012EA10F0841B203C5B880F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD287904696D646E8D7141244D9557B0C6F5D003);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// string message = AndroidMessage;
		String_t* L_0 = __this->___AndroidMessage_7;
		V_0 = L_0;
		// Debug.Log("Received message from Android: " + message);
		String_t* L_1 = V_0;
		String_t* L_2;
		L_2 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralFD287904696D646E8D7141244D9557B0C6F5D003, L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_2, NULL);
		// if (string.IsNullOrEmpty(message)) return;
		String_t* L_3 = V_0;
		bool L_4;
		L_4 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_3, NULL);
		if (!L_4)
		{
			goto IL_0020;
		}
	}
	{
		// if (string.IsNullOrEmpty(message)) return;
		return;
	}

IL_0020:
	{
		// if (!message.Equals("organic", StringComparison.OrdinalIgnoreCase))
		String_t* L_5 = V_0;
		NullCheck(L_5);
		bool L_6;
		L_6 = String_Equals_m7BDFC0B951005B9DC2BAED464AFE68FF7E9ACE5A(L_5, _stringLiteral467E141EA4AD8622B0ACCD7E96619F6FDC12DD21, 5, NULL);
		if (L_6)
		{
			goto IL_0047;
		}
	}
	{
		// AndroidJavaClass jc = new AndroidJavaClass("olyehijhfb.eworcyut.wkgfahvnqg.UnityPlayerActivity");
		AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* L_7 = (AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03*)il2cpp_codegen_object_new(AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		AndroidJavaClass__ctor_mB5466169E1151B8CC44C8FED234D79984B431389(L_7, _stringLiteralE9145F1641B02E019012EA10F0841B203C5B880F, NULL);
		// jc.CallStatic("analyseAjust");
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_8;
		L_8 = Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_inline(Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		NullCheck(L_7);
		AndroidJavaObject_CallStatic_mB677DE04369EDD8E6DECAF2F233116EE1F06555C(L_7, _stringLiteral8CBC0B20B7980F8F53D0AAAAD321F93E251E1FA1, L_8, NULL);
	}

IL_0047:
	{
		// }
		return;
	}
}
// System.Void GameData::ShowGoogleInterstitialAdAd()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameData_ShowGoogleInterstitialAdAd_mFDC40583FA00AB447FB4A7E21C711A51BCC5B514 (GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4CEA8A0063213A8412FA6B1C943CA05E38FD880E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE9145F1641B02E019012EA10F0841B203C5B880F);
		s_Il2CppMethodInitialized = true;
	}
	{
		// AndroidJavaClass jc = new AndroidJavaClass("olyehijhfb.eworcyut.wkgfahvnqg.UnityPlayerActivity");
		AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* L_0 = (AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03*)il2cpp_codegen_object_new(AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		AndroidJavaClass__ctor_mB5466169E1151B8CC44C8FED234D79984B431389(L_0, _stringLiteralE9145F1641B02E019012EA10F0841B203C5B880F, NULL);
		// jc.CallStatic("ShowInterstitialAd");
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1;
		L_1 = Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_inline(Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		NullCheck(L_0);
		AndroidJavaObject_CallStatic_mB677DE04369EDD8E6DECAF2F233116EE1F06555C(L_0, _stringLiteral4CEA8A0063213A8412FA6B1C943CA05E38FD880E, L_1, NULL);
		// }
		return;
	}
}
// System.Void GameData::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameData__ctor_mA9048174D2C20A10AD865A4B919045878E27099A (GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_mBCB1DDC744D6A952DA9059FAF2B78CD80D0B17A0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public bool boolPlay = true;
		__this->___boolPlay_2 = (bool)1;
		// public float gameTimer = 10;
		__this->___gameTimer_5 = (10.0f);
		// public string AndroidMessage = "";
		__this->___AndroidMessage_7 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AndroidMessage_7), (void*)_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		BaseManager_1__ctor_mBCB1DDC744D6A952DA9059FAF2B78CD80D0B17A0(__this, BaseManager_1__ctor_mBCB1DDC744D6A952DA9059FAF2B78CD80D0B17A0_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void HallScene::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Awake_m7299900D412665B48023FF17B01408CB501910A7 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// InintView();
		HallScene_InintView_m31696BDD1C9BEBC02E3238AEFB398D84F86C63FC(__this, NULL);
		// }
		return;
	}
}
// System.Void HallScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_InintView_m31696BDD1C9BEBC02E3238AEFB398D84F86C63FC (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m42DA4DEA19EB60D80CBED7413ADEB27FA033C77B_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// audio = GetComponent<AudioSource>();
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_0;
		L_0 = Component_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m42DA4DEA19EB60D80CBED7413ADEB27FA033C77B(__this, Component_GetComponent_TisAudioSource_t871AC2272F896738252F04EE949AEF5B241D3299_m42DA4DEA19EB60D80CBED7413ADEB27FA033C77B_RuntimeMethod_var);
		__this->___audio_13 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___audio_13), (void*)L_0);
		// }
		return;
	}
}
// System.Void HallScene::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnEnable_mC3EE676F008A31B2465654C231E406F750D4BF23 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// gameTimer = gameData.gameTimer;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0 = __this->___gameData_12;
		NullCheck(L_0);
		float L_1 = L_0->___gameTimer_5;
		__this->___gameTimer_14 = L_1;
		// UpdateTime();
		HallScene_UpdateTime_m53A4F3F931334124691E572BE59782DE11A4A79E(__this, NULL);
		// UpdateView();
		HallScene_UpdateView_m0261A21525E07CABA321C768AB0D52BCE47FBF16(__this, NULL);
		// }
		return;
	}
}
// System.Void HallScene::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Reset_m10461004FC58415E02B0786D15A894BB7B7D82CE (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void HallScene::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Start_mCE779623E33DDD2D99D4FD8E4D9210AFA2958CA4 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m5F6E80E4D3876B809AAA9A749CE6A07FC7C6336D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// timer_game = TimerMgr.Getinstance();
		TimerMgr_t65C60CDCDF8974C9F52F9611559BA850C7B9EB8A* L_0;
		L_0 = BaseManager_1_Getinstance_m5F6E80E4D3876B809AAA9A749CE6A07FC7C6336D(BaseManager_1_Getinstance_m5F6E80E4D3876B809AAA9A749CE6A07FC7C6336D_RuntimeMethod_var);
		__this->___timer_game_11 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___timer_game_11), (void*)L_0);
		// }
		return;
	}
}
// System.Void HallScene::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Update_m9D02FEA5759A8D44BAFEEEFD5A310614CBC251D1 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// if (boolStartTime)
		bool L_0 = __this->___boolStartTime_17;
		if (!L_0)
		{
			goto IL_000e;
		}
	}
	{
		// UpdateDeltaTime();
		HallScene_UpdateDeltaTime_mA9FF07331BA7577C57FC1242E8EE2E3B15339898(__this, NULL);
	}

IL_000e:
	{
		// PdResult();
		HallScene_PdResult_m3D7443D35A2D2697C8E5707D877E5618075C1A59(__this, NULL);
		// if (!string.IsNullOrEmpty(gameData.AndroidMessage) &&isCheckAndroidMessage)
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_1 = __this->___gameData_12;
		NullCheck(L_1);
		String_t* L_2 = L_1->___AndroidMessage_7;
		bool L_3;
		L_3 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_2, NULL);
		if (L_3)
		{
			goto IL_0040;
		}
	}
	{
		bool L_4 = __this->___isCheckAndroidMessage_21;
		if (!L_4)
		{
			goto IL_0040;
		}
	}
	{
		// gameData.AnalyseAjust();
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_5 = __this->___gameData_12;
		NullCheck(L_5);
		GameData_AnalyseAjust_m9F9CE5CD4B8AA2B44DAFF13778FD881E5CB9F8A5(L_5, NULL);
		// isCheckAndroidMessage = false;
		__this->___isCheckAndroidMessage_21 = (bool)0;
	}

IL_0040:
	{
		// }
		return;
	}
}
// System.Void HallScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateView_m0261A21525E07CABA321C768AB0D52BCE47FBF16 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Collections.IEnumerator HallScene::ShowStartObj()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HallScene_ShowStartObj_m70799452043A22E17B7403557A4EA9F57848998A (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* L_0 = (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41*)il2cpp_codegen_object_new(U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CShowStartObjU3Ed__25__ctor_mD6FFBAD6B84D64550936A45E19D44759077C8C41(L_0, 0, NULL);
		return L_0;
	}
}
// System.Void HallScene::OnBtnClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnBtnClick_m5A705C063B6B7FFEFEEA4D9E063DA0EE7B4D998C (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral422457F901751FA3B57100A103387F681147FE63);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral75BA92A17A01F0E039DA3C7128CDA319E62D1F62);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBD02D6E0891A74DFC91263FF3056D5D5BD982D91);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* G_B7_0 = NULL;
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* G_B6_0 = NULL;
	int32_t G_B8_0 = 0;
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* G_B8_1 = NULL;
	{
		// GameObject btnObj = EventSystem.current.currentSelectedGameObject;
		il2cpp_codegen_runtime_class_init_inline(EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016(NULL);
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline(L_0, NULL);
		// string btnName = btnObj.name;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_1, NULL);
		V_0 = L_2;
		// Debug.Log(btnName);
		String_t* L_3 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_3, NULL);
		String_t* L_4 = V_0;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteralBD02D6E0891A74DFC91263FF3056D5D5BD982D91, NULL);
		if (L_5)
		{
			goto IL_004b;
		}
	}
	{
		String_t* L_6 = V_0;
		bool L_7;
		L_7 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_6, _stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743, NULL);
		if (L_7)
		{
			goto IL_0082;
		}
	}
	{
		String_t* L_8 = V_0;
		bool L_9;
		L_9 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_8, _stringLiteral75BA92A17A01F0E039DA3C7128CDA319E62D1F62, NULL);
		if (L_9)
		{
			goto IL_0082;
		}
	}
	{
		String_t* L_10 = V_0;
		bool L_11;
		L_11 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_10, _stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63, NULL);
		if (L_11)
		{
			goto IL_0099;
		}
	}
	{
		return;
	}

IL_004b:
	{
		// gameData.boolPlay = !gameData.boolPlay;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_12 = __this->___gameData_12;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_13 = __this->___gameData_12;
		NullCheck(L_13);
		bool L_14 = L_13->___boolPlay_2;
		NullCheck(L_12);
		L_12->___boolPlay_2 = (bool)((((int32_t)L_14) == ((int32_t)0))? 1 : 0);
		// audio.volume = gameData.boolPlay ? 1 : 0;
		AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* L_15 = __this->___audio_13;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_16 = __this->___gameData_12;
		NullCheck(L_16);
		bool L_17 = L_16->___boolPlay_2;
		G_B6_0 = L_15;
		if (L_17)
		{
			G_B7_0 = L_15;
			goto IL_007a;
		}
	}
	{
		G_B8_0 = 0;
		G_B8_1 = G_B6_0;
		goto IL_007b;
	}

IL_007a:
	{
		G_B8_0 = 1;
		G_B8_1 = G_B7_0;
	}

IL_007b:
	{
		NullCheck(G_B8_1);
		AudioSource_set_volume_mD902BBDBBDE0E3C148609BF3C05096148E90F2C0(G_B8_1, ((float)G_B8_0), NULL);
		// break;
		return;
	}

IL_0082:
	{
		// Pop_result.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_18 = __this->___Pop_result_6;
		NullCheck(L_18);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_18, (bool)0, NULL);
		// SceneManager.LoadScene("LoadScene");
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(_stringLiteral422457F901751FA3B57100A103387F681147FE63, NULL);
		// break;
		return;
	}

IL_0099:
	{
		// GameStart();
		HallScene_GameStart_mE5436D22642A4AA8FC0BDA0C7FF60B89DB3FBE65(__this, NULL);
		// }
		return;
	}
}
// System.Void HallScene::OnBtnProClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnBtnProClick_mE6728567B222834E73E2794EE7F0D30F7EAC6926 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2064F80F811DB79A33C4E51C10221454E30C74AE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral21ED4C7AF50D987589A9029FC0422151BE3A0FC2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE91FE173F59B063D620A934CE1A010F2B114C1F3);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	String_t* V_1 = NULL;
	{
		// GameObject btnObj = EventSystem.current.currentSelectedGameObject;
		il2cpp_codegen_runtime_class_init_inline(EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016(NULL);
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline(L_0, NULL);
		V_0 = L_1;
		// string btnName = btnObj.name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = V_0;
		NullCheck(L_2);
		String_t* L_3;
		L_3 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_2, NULL);
		V_1 = L_3;
		String_t* L_4 = V_1;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteralE91FE173F59B063D620A934CE1A010F2B114C1F3, NULL);
		if (L_5)
		{
			goto IL_0039;
		}
	}
	{
		String_t* L_6 = V_1;
		bool L_7;
		L_7 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_6, _stringLiteral21ED4C7AF50D987589A9029FC0422151BE3A0FC2, NULL);
		if (L_7)
		{
			goto IL_0039;
		}
	}
	{
		String_t* L_8 = V_1;
		bool L_9;
		L_9 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_8, _stringLiteral2064F80F811DB79A33C4E51C10221454E30C74AE, NULL);
		if (!L_9)
		{
			goto IL_0040;
		}
	}

IL_0039:
	{
		// Prohandel(btnObj);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_10 = V_0;
		HallScene_Prohandel_m2B1470028E31DCF32F6AE5F9C6517F25C9DBB85C(__this, L_10, NULL);
	}

IL_0040:
	{
		// }
		return;
	}
}
// System.Void HallScene::OnBtnLiClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnBtnLiClick_m1D1B10BD47C34F69ADC96D8736CF0DB39F5C279C (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2064F80F811DB79A33C4E51C10221454E30C74AE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral21ED4C7AF50D987589A9029FC0422151BE3A0FC2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7454695E25D304C65D0C1333D8008E862569CAE9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE91FE173F59B063D620A934CE1A010F2B114C1F3);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// GameObject btnObj = EventSystem.current.currentSelectedGameObject;
		il2cpp_codegen_runtime_class_init_inline(EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016(NULL);
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline(L_0, NULL);
		// string btnName = btnObj.name;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_1, NULL);
		V_0 = L_2;
		String_t* L_3 = V_0;
		bool L_4;
		L_4 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_3, _stringLiteralE91FE173F59B063D620A934CE1A010F2B114C1F3, NULL);
		if (L_4)
		{
			goto IL_0044;
		}
	}
	{
		String_t* L_5 = V_0;
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_5, _stringLiteral21ED4C7AF50D987589A9029FC0422151BE3A0FC2, NULL);
		if (L_6)
		{
			goto IL_0044;
		}
	}
	{
		String_t* L_7 = V_0;
		bool L_8;
		L_8 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_7, _stringLiteral2064F80F811DB79A33C4E51C10221454E30C74AE, NULL);
		if (L_8)
		{
			goto IL_0044;
		}
	}
	{
		String_t* L_9 = V_0;
		bool L_10;
		L_10 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_9, _stringLiteral7454695E25D304C65D0C1333D8008E862569CAE9, NULL);
		if (!L_10)
		{
			goto IL_004b;
		}
	}

IL_0044:
	{
		// Lihandel(btnName);
		String_t* L_11 = V_0;
		HallScene_Lihandel_m30E85664D6605DC13C0EF4D2D77DED93BE026A04(__this, L_11, NULL);
	}

IL_004b:
	{
		// }
		return;
	}
}
// System.Void HallScene::Prohandel(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Prohandel_m2B1470028E31DCF32F6AE5F9C6517F25C9DBB85C (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_btnObj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// gameData.boolClick = !gameData.boolClick;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0 = __this->___gameData_12;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_1 = __this->___gameData_12;
		NullCheck(L_1);
		bool L_2 = L_1->___boolClick_3;
		NullCheck(L_0);
		L_0->___boolClick_3 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		// string indexPro = btnObj.GetComponent<Image>().sprite.name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = ___0_btnObj;
		NullCheck(L_3);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_4;
		L_4 = GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D(L_3, GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D_RuntimeMethod_var);
		NullCheck(L_4);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_5;
		L_5 = Image_get_sprite_mB2AA377708722E100574F6F75BC102513BB3BCB1_inline(L_4, NULL);
		NullCheck(L_5);
		String_t* L_6;
		L_6 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_5, NULL);
		V_0 = L_6;
		// selecPro = int.Parse(indexPro);
		String_t* L_7 = V_0;
		int32_t L_8;
		L_8 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_7, NULL);
		__this->___selecPro_19 = L_8;
		// }
		return;
	}
}
// System.Void HallScene::Lihandel(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_Lihandel_m30E85664D6605DC13C0EF4D2D77DED93BE026A04 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, String_t* ___0_btnName, const RuntimeMethod* method) 
{
	{
		// if (!gameData.boolClick) return;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0 = __this->___gameData_12;
		NullCheck(L_0);
		bool L_1 = L_0->___boolClick_3;
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!gameData.boolClick) return;
		return;
	}

IL_000e:
	{
		// gameData.boolClick = false;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_2 = __this->___gameData_12;
		NullCheck(L_2);
		L_2->___boolClick_3 = (bool)0;
		// selecLi = int.Parse(btnName);
		String_t* L_3 = ___0_btnName;
		int32_t L_4;
		L_4 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_3, NULL);
		__this->___selecLi_20 = L_4;
		// icon_li[selecLi - 1].sprite = spriteArr[selecPro - 1];
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_5 = __this->___icon_li_10;
		int32_t L_6 = __this->___selecLi_20;
		NullCheck(L_5);
		int32_t L_7 = ((int32_t)il2cpp_codegen_subtract(L_6, 1));
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* L_9 = __this->___spriteArr_8;
		int32_t L_10 = __this->___selecPro_19;
		NullCheck(L_9);
		int32_t L_11 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_12 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_11));
		NullCheck(L_8);
		Image_set_sprite_mC0C248340BA27AAEE56855A3FAFA0D8CA12956DE(L_8, L_12, NULL);
		// icon_li[selecLi - 1].SetNativeSize();
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_13 = __this->___icon_li_10;
		int32_t L_14 = __this->___selecLi_20;
		NullCheck(L_13);
		int32_t L_15 = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_16);
		VirtualActionInvoker0::Invoke(45 /* System.Void UnityEngine.UI.Graphic::SetNativeSize() */, L_16);
		// }
		return;
	}
}
// System.Void HallScene::UpdateDeltaTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateDeltaTime_mA9FF07331BA7577C57FC1242E8EE2E3B15339898 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral422457F901751FA3B57100A103387F681147FE63);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!boolStartTime) return;
		bool L_0 = __this->___boolStartTime_17;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// if (!boolStartTime) return;
		return;
	}

IL_0009:
	{
		// if (gameTimer > 0)
		float L_1 = __this->___gameTimer_14;
		if ((!(((float)L_1) > ((float)(0.0f)))))
		{
			goto IL_0063;
		}
	}
	{
		// gameTimer -= Time.deltaTime;
		float L_2 = __this->___gameTimer_14;
		float L_3;
		L_3 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		__this->___gameTimer_14 = ((float)il2cpp_codegen_subtract(L_2, L_3));
		// if (gameTimer <= 0)
		float L_4 = __this->___gameTimer_14;
		if ((!(((float)L_4) <= ((float)(0.0f)))))
		{
			goto IL_005d;
		}
	}
	{
		// gameTimer = 0;
		__this->___gameTimer_14 = (0.0f);
		// gameData.boolFail = true;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_5 = __this->___gameData_12;
		NullCheck(L_5);
		L_5->___boolFail_6 = (bool)1;
		// boolStartTime = false;
		__this->___boolStartTime_17 = (bool)0;
		// SceneManager.LoadScene("LoadScene");
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(_stringLiteral422457F901751FA3B57100A103387F681147FE63, NULL);
	}

IL_005d:
	{
		// UpdateTime();
		HallScene_UpdateTime_m53A4F3F931334124691E572BE59782DE11A4A79E(__this, NULL);
	}

IL_0063:
	{
		// }
		return;
	}
}
// System.Void HallScene::UpdateTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateTime_m53A4F3F931334124691E572BE59782DE11A4A79E (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral49C2C4CBD74690CC3F0B4127393BEA222F0A5B31);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD3C6FF105F16F36B05CE62DC0895F7A6B90F6ED8);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// if (!text_time) return;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___text_time_5;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!text_time) return;
		return;
	}

IL_000e:
	{
		// int minutes = Mathf.FloorToInt(gameTimer / 60);
		float L_2 = __this->___gameTimer_14;
		int32_t L_3;
		L_3 = Mathf_FloorToInt_m2A39AE881CAEE6B6A4B3BFEF9CA1ED40625F5AB7_inline(((float)(L_2/(60.0f))), NULL);
		V_0 = L_3;
		// int seconds = Mathf.FloorToInt(gameTimer % 60);
		float L_4 = __this->___gameTimer_14;
		int32_t L_5;
		L_5 = Mathf_FloorToInt_m2A39AE881CAEE6B6A4B3BFEF9CA1ED40625F5AB7_inline((fmodf(L_4, (60.0f))), NULL);
		V_1 = L_5;
		// text_time.text = "Time:" + string.Format("{0:00}:{1:00}", minutes, seconds);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_6 = __this->___text_time_5;
		int32_t L_7 = V_0;
		int32_t L_8 = L_7;
		RuntimeObject* L_9 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_8);
		int32_t L_10 = V_1;
		int32_t L_11 = L_10;
		RuntimeObject* L_12 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_11);
		String_t* L_13;
		L_13 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralD3C6FF105F16F36B05CE62DC0895F7A6B90F6ED8, L_9, L_12, NULL);
		String_t* L_14;
		L_14 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral49C2C4CBD74690CC3F0B4127393BEA222F0A5B31, L_13, NULL);
		NullCheck(L_6);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_6, L_14);
		// }
		return;
	}
}
// System.Void HallScene::UpdateScore()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateScore_m0B03238B4568E07C02C7FE2690F034C8BFA611BC (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!text_score) return;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___text_score_4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!text_score) return;
		return;
	}

IL_000e:
	{
		// gameData.currentScore++;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_2 = __this->___gameData_12;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_3 = L_2;
		NullCheck(L_3);
		int32_t L_4 = L_3->___currentScore_4;
		NullCheck(L_3);
		L_3->___currentScore_4 = ((int32_t)il2cpp_codegen_add(L_4, 1));
		// boolStartTime = false;
		__this->___boolStartTime_17 = (bool)0;
		// currentScore =gameData.currentScore ;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_5 = __this->___gameData_12;
		NullCheck(L_5);
		int32_t L_6 = L_5->___currentScore_4;
		__this->___currentScore_16 = ((float)L_6);
		// text_score.text = currentScore.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_7 = __this->___text_score_4;
		float* L_8 = (&__this->___currentScore_16);
		String_t* L_9;
		L_9 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_8, NULL);
		NullCheck(L_7);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_7, L_9);
		// }
		return;
	}
}
// System.Void HallScene::GameStart()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_GameStart_mE5436D22642A4AA8FC0BDA0C7FF60B89DB3FBE65 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// boolStartTime = true;
		__this->___boolStartTime_17 = (bool)1;
		// btn_start.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___btn_start_7;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// UpdateRegPro();
		HallScene_UpdateRegPro_m6F253F9BBE1C2D5C491346A5A8F503AC2AC34345(__this, NULL);
		// }
		return;
	}
}
// System.Void HallScene::UpdateRegPro()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_UpdateRegPro_m6F253F9BBE1C2D5C491346A5A8F503AC2AC34345 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		// List<int> numbers = new List<int>();
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_0 = (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*)il2cpp_codegen_object_new(List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8(L_0, List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		V_0 = L_0;
		goto IL_0023;
	}

IL_0008:
	{
		// int randomNumber = Random.Range(0, 4);
		int32_t L_1;
		L_1 = Random_Range_m6763D9767F033357F88B6637F048F4ACA4123B68(0, 4, NULL);
		V_1 = L_1;
		// if (randomNumber != 0 && !numbers.Contains(randomNumber))
		int32_t L_2 = V_1;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_3 = V_0;
		int32_t L_4 = V_1;
		NullCheck(L_3);
		bool L_5;
		L_5 = List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B(L_3, L_4, List_1_Contains_m4FD96E89F15844C90032C7386BAB528817F1FF5B_RuntimeMethod_var);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		// numbers.Add(randomNumber);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_6 = V_0;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline(L_6, L_7, List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
	}

IL_0023:
	{
		// while (numbers.Count < 3) // ??5????
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_inline(L_8, List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		if ((((int32_t)L_9) < ((int32_t)3)))
		{
			goto IL_0008;
		}
	}
	{
		// for (int i = 0; i < 3; i++)
		V_2 = 0;
		goto IL_005c;
	}

IL_0030:
	{
		// icon_pro[i].sprite = spriteArr[numbers[i]];
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_10 = __this->___icon_pro_9;
		int32_t L_11 = V_2;
		NullCheck(L_10);
		int32_t L_12 = L_11;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_13 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		SpriteU5BU5D_tCEE379E10CAD9DBFA770B331480592548ED0EA1B* L_14 = __this->___spriteArr_8;
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_15 = V_0;
		int32_t L_16 = V_2;
		NullCheck(L_15);
		int32_t L_17;
		L_17 = List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D(L_15, L_16, List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		NullCheck(L_14);
		int32_t L_18 = L_17;
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_19 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_18));
		NullCheck(L_13);
		Image_set_sprite_mC0C248340BA27AAEE56855A3FAFA0D8CA12956DE(L_13, L_19, NULL);
		// icon_pro[i].SetNativeSize();
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_20 = __this->___icon_pro_9;
		int32_t L_21 = V_2;
		NullCheck(L_20);
		int32_t L_22 = L_21;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_23 = (L_20)->GetAt(static_cast<il2cpp_array_size_t>(L_22));
		NullCheck(L_23);
		VirtualActionInvoker0::Invoke(45 /* System.Void UnityEngine.UI.Graphic::SetNativeSize() */, L_23);
		// for (int i = 0; i < 3; i++)
		int32_t L_24 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_005c:
	{
		// for (int i = 0; i < 3; i++)
		int32_t L_25 = V_2;
		if ((((int32_t)L_25) < ((int32_t)3)))
		{
			goto IL_0030;
		}
	}
	{
		// }
		return;
	}
}
// System.Void HallScene::GameOver()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_GameOver_m2AC337604D0B14F9B2022C735244CEF184F9316D (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void HallScene::PdResult()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_PdResult_m3D7443D35A2D2697C8E5707D877E5618075C1A59 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// if (!boolStartTime) return;
		bool L_0 = __this->___boolStartTime_17;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// if (!boolStartTime) return;
		return;
	}

IL_0009:
	{
		// for (int i = 0; i < icon_li.Length; i++)
		V_0 = 0;
		goto IL_0036;
	}

IL_000d:
	{
		// string indexSprite = icon_li[i].sprite.name;
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_1 = __this->___icon_li_10;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		NullCheck(L_4);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_5;
		L_5 = Image_get_sprite_mB2AA377708722E100574F6F75BC102513BB3BCB1_inline(L_4, NULL);
		NullCheck(L_5);
		String_t* L_6;
		L_6 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_5, NULL);
		// if (indexSprite != (i + 1).ToString())
		int32_t L_7 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_7, 1));
		String_t* L_8;
		L_8 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_1), NULL);
		bool L_9;
		L_9 = String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6(L_6, L_8, NULL);
		if (!L_9)
		{
			goto IL_0032;
		}
	}
	{
		// return;
		return;
	}

IL_0032:
	{
		// for (int i = 0; i < icon_li.Length; i++)
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0036:
	{
		// for (int i = 0; i < icon_li.Length; i++)
		int32_t L_11 = V_0;
		ImageU5BU5D_t8869694C217655DA7B1315DC02C80F1308B78B78* L_12 = __this->___icon_li_10;
		NullCheck(L_12);
		if ((((int32_t)L_11) < ((int32_t)((int32_t)(((RuntimeArray*)L_12)->max_length)))))
		{
			goto IL_000d;
		}
	}
	{
		// Pop_result.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13 = __this->___Pop_result_6;
		NullCheck(L_13);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_13, (bool)1, NULL);
		// btn_start.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14 = __this->___btn_start_7;
		NullCheck(L_14);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_14, (bool)1, NULL);
		// UpdateScore();
		HallScene_UpdateScore_m0B03238B4568E07C02C7FE2690F034C8BFA611BC(__this, NULL);
		// }
		return;
	}
}
// System.Int32 HallScene::getSpriteIndex(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HallScene_getSpriteIndex_m79A3DCB2ADD763FFE52A27003ADA013AEBF85DC0 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_objSprite, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// string indexPro = objSprite.GetComponent<Image>().sprite.name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_objSprite;
		NullCheck(L_0);
		Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* L_1;
		L_1 = GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D(L_0, GameObject_GetComponent_TisImage_tBC1D03F63BF71132E9A5E472B8742F172A011E7E_mA59EA7D5F9133B2593F4AB70B099928BA955EE7D_RuntimeMethod_var);
		NullCheck(L_1);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_2;
		L_2 = Image_get_sprite_mB2AA377708722E100574F6F75BC102513BB3BCB1_inline(L_1, NULL);
		NullCheck(L_2);
		String_t* L_3;
		L_3 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_2, NULL);
		// int indexSprite = int.Parse(indexPro);
		int32_t L_4;
		L_4 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_3, NULL);
		// return indexSprite;
		return L_4;
	}
}
// System.Void HallScene::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnApplicationQuit_mDC2265DAD17AF7C0658F3726DB1B2BF717561682 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void HallScene::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnDisable_m2D717199ABABCCD585E1EDCCBFE51EC5273F225B (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void HallScene::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene_OnDestroy_m366B089B876CE4192733279BC6FEDD10047ED7FA (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void HallScene::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HallScene__ctor_m6A32F50FBCC77C9BA88703985DEAC7629A4D6A17 (HallScene_t50D8B386DA5E61884A4D5AE476E018ECCC084A2C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameData gameData = GameData.Getinstance();
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0;
		L_0 = BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4(BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		__this->___gameData_12 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___gameData_12), (void*)L_0);
		// private float gameTimer = 10.0f;
		__this->___gameTimer_14 = (10.0f);
		// private bool isCheckAndroidMessage = true;
		__this->___isCheckAndroidMessage_21 = (bool)1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void HallScene/<ShowStartObj>d__25::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__25__ctor_mD6FFBAD6B84D64550936A45E19D44759077C8C41 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void HallScene/<ShowStartObj>d__25::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__25_System_IDisposable_Dispose_mEBE73FAFA273580F6EAB3CBDF191496E1DBFAC76 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean HallScene/<ShowStartObj>d__25::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CShowStartObjU3Ed__25_MoveNext_m49A1AC09E843B260B022D15C622667174ADE0012 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		int32_t L_1 = V_0;
		switch (L_1)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_003b;
			}
			case 2:
			{
				goto IL_005b;
			}
		}
	}
	{
		return (bool)0;
	}

IL_001b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// yield return new WaitForSeconds(1.5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_2 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_2, (1.5f), NULL);
		__this->___U3CU3E2__current_1 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_2);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_003b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// yield return new WaitForSeconds(0.5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_3 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_3, (0.5f), NULL);
		__this->___U3CU3E2__current_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_3);
		__this->___U3CU3E1__state_0 = 2;
		return (bool)1;
	}

IL_005b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// }
		return (bool)0;
	}
}
// System.Object HallScene/<ShowStartObj>d__25::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CShowStartObjU3Ed__25_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m1889D50E4F1BBB09C6C81E2E1B2EB2A96D0B3EEC (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void HallScene/<ShowStartObj>d__25::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__25_System_Collections_IEnumerator_Reset_m4FAE2B3698E68C6ACB1C36CAE49DDF933BD70068 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CShowStartObjU3Ed__25_System_Collections_IEnumerator_Reset_m4FAE2B3698E68C6ACB1C36CAE49DDF933BD70068_RuntimeMethod_var)));
	}
}
// System.Object HallScene/<ShowStartObj>d__25::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CShowStartObjU3Ed__25_System_Collections_IEnumerator_get_Current_m591EDC95C14EFE6F62419E155C78DA1EA95B3825 (U3CShowStartObjU3Ed__25_t8A558A54E286DF61D39AC8D1BDFEC5FA1E3BCB41* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LoadScene::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_Awake_mE48E5D4590D180968F3A04237BCA798EB9C099C8 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// InintView();
		LoadScene_InintView_m848AFDAB275711BBC2032390AE7694E82045F7F4(__this, NULL);
		// }
		return;
	}
}
// System.Void LoadScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_InintView_m848AFDAB275711BBC2032390AE7694E82045F7F4 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_OnEnable_mA7718C1315BDD6B72A5C714A7045842D5F53FE78 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// UpdateView();
		LoadScene_UpdateView_mA94854795433FC09421CB8ACA0A8F3BC0FF5F8CD(__this, NULL);
		// }
		return;
	}
}
// System.Void LoadScene::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_Reset_m5BC67F53C821D4A1CC11A9CBF285042D468E31AD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_Start_mA8000B70D4FE85E09903D344D4B3678F22325E30 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_Update_mA2E0C341B3F9DC472A465E13EB9BEA09EC7ACEF0 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (text_load.gameObject&&text_load.gameObject.activeSelf)
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___text_load_5;
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_1, NULL);
		if (!L_2)
		{
			goto IL_0031;
		}
	}
	{
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_3 = __this->___text_load_5;
		NullCheck(L_3);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
		L_4 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_3, NULL);
		NullCheck(L_4);
		bool L_5;
		L_5 = GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368(L_4, NULL);
		if (!L_5)
		{
			goto IL_0031;
		}
	}
	{
		// StartCoroutine(ShowStartObj());
		RuntimeObject* L_6;
		L_6 = LoadScene_ShowStartObj_mCDB329E7C3CDAD36AE7088EE4DC798E3635B586F(__this, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_7;
		L_7 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_6, NULL);
	}

IL_0031:
	{
		// }
		return;
	}
}
// System.Void LoadScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_UpdateView_mA94854795433FC09421CB8ACA0A8F3BC0FF5F8CD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Collections.IEnumerator LoadScene::ShowStartObj()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* LoadScene_ShowStartObj_mCDB329E7C3CDAD36AE7088EE4DC798E3635B586F (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* L_0 = (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944*)il2cpp_codegen_object_new(U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CShowStartObjU3Ed__10__ctor_mF39C967B2CE23264C4C9FF4EE81CCA6A94271248(L_0, 0, NULL);
		U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Void LoadScene::OnBtnClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_OnBtnClick_m98CA2C239B8A256E8C59AF151CF15BE1CD9D35CA (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral23EB829BB546619387DBE1C61ED5889563B83EA4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6E3E0318C851B84A160E7BB95BCF95485620A391);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCB26D0F80C241D4EA4617B2C4982285182E48882);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// GameObject btnObj = EventSystem.current.currentSelectedGameObject;
		il2cpp_codegen_runtime_class_init_inline(EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016(NULL);
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline(L_0, NULL);
		// string btnName = btnObj.name;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_1, NULL);
		V_0 = L_2;
		String_t* L_3 = V_0;
		bool L_4;
		L_4 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_3, _stringLiteralCB26D0F80C241D4EA4617B2C4982285182E48882, NULL);
		if (L_4)
		{
			goto IL_0038;
		}
	}
	{
		String_t* L_5 = V_0;
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_5, _stringLiteral6E3E0318C851B84A160E7BB95BCF95485620A391, NULL);
		if (L_6)
		{
			goto IL_0038;
		}
	}
	{
		String_t* L_7 = V_0;
		bool L_8;
		L_8 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_7, _stringLiteral23EB829BB546619387DBE1C61ED5889563B83EA4, NULL);
		if (L_8)
		{
			goto IL_003f;
		}
	}
	{
		return;
	}

IL_0038:
	{
		// LoadSceneHall();
		LoadScene_LoadSceneHall_m8954803260BB298171EDFB201E4ED1FCF4A8BA56(__this, NULL);
		// break;
		return;
	}

IL_003f:
	{
		// ChangeStatueLoad(false);
		LoadScene_ChangeStatueLoad_m4D36E62F61C5FE24229089A8B794A5EF01409AAD(__this, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void LoadScene::LoadSceneHall()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_LoadSceneHall_m8954803260BB298171EDFB201E4ED1FCF4A8BA56 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC20F0AF5CF583A987CF53E1C5B19E24CA620A7D2);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GameData.Getinstance().gameTimer = Random.Range(5, 26);
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0;
		L_0 = BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4(BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		int32_t L_1;
		L_1 = Random_Range_m6763D9767F033357F88B6637F048F4ACA4123B68(5, ((int32_t)26), NULL);
		NullCheck(L_0);
		L_0->___gameTimer_5 = ((float)L_1);
		// SceneManager.LoadScene("HallScene");
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(_stringLiteralC20F0AF5CF583A987CF53E1C5B19E24CA620A7D2, NULL);
		// }
		return;
	}
}
// System.Void LoadScene::ChangeStatueLoad(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_ChangeStatueLoad_m4D36E62F61C5FE24229089A8B794A5EF01409AAD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, bool ___0_statues, const RuntimeMethod* method) 
{
	{
		// btn_obj.SetActive(statues);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___btn_obj_4;
		bool L_1 = ___0_statues;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, L_1, NULL);
		// text_load.gameObject.SetActive(!statues);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_2 = __this->___text_load_5;
		NullCheck(L_2);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3;
		L_3 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_2, NULL);
		bool L_4 = ___0_statues;
		NullCheck(L_3);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_3, (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0), NULL);
		// }
		return;
	}
}
// System.Void LoadScene::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_OnApplicationQuit_mCEE49A1D63BABF5D9524544C3789797A36317CF9 (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_OnDisable_m58A8646C4D9894B32834E899B9B4777B49D4F98A (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene_OnDestroy_mA6CB83056B9AC22316D9A92E960C35615A01791D (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void LoadScene::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LoadScene__ctor_m560E29BD726E67BB4572A9B8098DD97BEFFF63DD (LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LoadScene/<ShowStartObj>d__10::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__10__ctor_mF39C967B2CE23264C4C9FF4EE81CCA6A94271248 (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void LoadScene/<ShowStartObj>d__10::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__10_System_IDisposable_Dispose_mADDBCB12B7AF4BE0C5B403FDC6B497C84E8679A6 (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean LoadScene/<ShowStartObj>d__10::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CShowStartObjU3Ed__10_MoveNext_m8081AAFC443DA622A65921905ADC2FF43CF5E6EF (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC3B5254FCC61D515E7907085297D572F36351F06);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* L_1 = __this->___U3CU3E4__this_2;
		V_1 = L_1;
		int32_t L_2 = V_0;
		switch (L_2)
		{
			case 0:
			{
				goto IL_0026;
			}
			case 1:
			{
				goto IL_0046;
			}
			case 2:
			{
				goto IL_0076;
			}
			case 3:
			{
				goto IL_009d;
			}
		}
	}
	{
		return (bool)0;
	}

IL_0026:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// yield return new WaitForSeconds(1.5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_3 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_3, (1.5f), NULL);
		__this->___U3CU3E2__current_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_3);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0046:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// text_load.text = "GAME START !";
		LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* L_4 = V_1;
		NullCheck(L_4);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_5 = L_4->___text_load_5;
		NullCheck(L_5);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_5, _stringLiteralC3B5254FCC61D515E7907085297D572F36351F06);
		// yield return new WaitForSeconds(0.5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_6 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_6, (0.5f), NULL);
		__this->___U3CU3E2__current_1 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_6);
		__this->___U3CU3E1__state_0 = 2;
		return (bool)1;
	}

IL_0076:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// ChangeStatueLoad(true);
		LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* L_7 = V_1;
		NullCheck(L_7);
		LoadScene_ChangeStatueLoad_m4D36E62F61C5FE24229089A8B794A5EF01409AAD(L_7, (bool)1, NULL);
		// yield return new WaitForSeconds(2.5f);
		WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3* L_8 = (WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3*)il2cpp_codegen_object_new(WaitForSeconds_tF179DF251655B8DF044952E70A60DF4B358A3DD3_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		WaitForSeconds__ctor_m579F95BADEDBAB4B3A7E302C6EE3995926EF2EFC(L_8, (2.5f), NULL);
		__this->___U3CU3E2__current_1 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_8);
		__this->___U3CU3E1__state_0 = 3;
		return (bool)1;
	}

IL_009d:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// LoadSceneHall();
		LoadScene_t13789E834A08B06FF59FCCEA1BA366FC2965E335* L_9 = V_1;
		NullCheck(L_9);
		LoadScene_LoadSceneHall_m8954803260BB298171EDFB201E4ED1FCF4A8BA56(L_9, NULL);
		// }
		return (bool)0;
	}
}
// System.Object LoadScene/<ShowStartObj>d__10::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CShowStartObjU3Ed__10_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_mBBC08A64FD9DB6D606815B8B2ACDB86DCD623B87 (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void LoadScene/<ShowStartObj>d__10::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CShowStartObjU3Ed__10_System_Collections_IEnumerator_Reset_m88DE256B46F127FD65E87558C3019A08737B3675 (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CShowStartObjU3Ed__10_System_Collections_IEnumerator_Reset_m88DE256B46F127FD65E87558C3019A08737B3675_RuntimeMethod_var)));
	}
}
// System.Object LoadScene/<ShowStartObj>d__10::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CShowStartObjU3Ed__10_System_Collections_IEnumerator_get_Current_m688251FEBC0EB7EBCA0EB1A675C887AE55AE274F (U3CShowStartObjU3Ed__10_t5A8F8C20ACA4C402DD69AB34CD47C0C734F27944* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void AndroidJavaCShap::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_Awake_mC69B875B134C6C3CAD7A225056FFFF603C0A8789 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// InintView();
		AndroidJavaCShap_InintView_mFF65FB98D810F0709B283EC1A5E853FC6761DF08(__this, NULL);
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_InintView_mFF65FB98D810F0709B283EC1A5E853FC6761DF08 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_OnEnable_mA9C93AD6E5FE1A81B45FC5E3C8EC3E1229F66857 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// UpdateView();
		AndroidJavaCShap_UpdateView_m92FE5422E3818C398AC5ADEF97246EF808329D26(__this, NULL);
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_Reset_m28B5FC19C585D590AE34F74A95E40A2D804E5169 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_Start_m05793EB07C2E00BA0A6353784A3BF54229A837D7 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_Update_m68785B46BF38690B1AF5B1798472A1185B3190C6 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_UpdateView_m92FE5422E3818C398AC5ADEF97246EF808329D26 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::AndroidMessage(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_AndroidMessage_m867CF75F687992A9D2D4529D68737238C38934A6 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, String_t* ___0_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral61E694FFA1F9C158F5F7ADB738F4D38EAE670E74);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Debug.Log("Unity??????AndroidMessage:::" + message);
		String_t* L_0 = ___0_message;
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral61E694FFA1F9C158F5F7ADB738F4D38EAE670E74, L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_1, NULL);
		// gameData.AndroidMessage = message;
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_2 = __this->___gameData_4;
		String_t* L_3 = ___0_message;
		NullCheck(L_2);
		L_2->___AndroidMessage_7 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&L_2->___AndroidMessage_7), (void*)L_3);
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::OnBtnClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_OnBtnClick_mC69B60A630A5F3F173D260AA32E9C2C2AF5D054A (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_OnApplicationQuit_mDC55B4735C60993517C2D53598309BFE73CD13CC (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_OnDisable_mD195F81A3C09848DDA38106179167CB8C096E975 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap_OnDestroy_m65A72415D23D1E87D6859F79065089D062C884FA (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void AndroidJavaCShap::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AndroidJavaCShap__ctor_m3A4D1D70CC6838E6C1FEBBA0C11F61ABCEA50353 (AndroidJavaCShap_t71F7C508E1B3294B14AC8FC01D2332A90DC2DE19* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private GameData gameData = GameData.Getinstance();
		GameData_t857DCFA51343FE2611A88BE4D943BDA16FBCE8B6* L_0;
		L_0 = BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4(BaseManager_1_Getinstance_m9D30BC8AA5943E71D2A15A23BA8C86848C0D25A4_RuntimeMethod_var);
		__this->___gameData_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___gameData_4), (void*)L_0);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.String Tools::GetRandom(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Tools_GetRandom_m50759DF2DA091555DB2897CE842922EF6D750139 (Tools_t3DF42EB905CE903A075617859FA36803BEC507C4* __this, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_arr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// Random ran = new Random();
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_0 = (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8*)il2cpp_codegen_object_new(Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC(L_0, NULL);
		// int n = ran.Next(arr.Length - 1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = ___0_arr;
		NullCheck(L_1);
		NullCheck(L_0);
		int32_t L_2;
		L_2 = VirtualFuncInvoker1< int32_t, int32_t >::Invoke(7 /* System.Int32 System.Random::Next(System.Int32) */, L_0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_1)->max_length)), 1)));
		V_0 = L_2;
		// return arr[n];
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = ___0_arr;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		String_t* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		return L_6;
	}
}
// System.Int32 Tools::GetRandomInt(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Tools_GetRandomInt_m8790578139FCFD9BF5272243F83FF20F9A0C16E4 (Tools_t3DF42EB905CE903A075617859FA36803BEC507C4* __this, int32_t ___0_minNum, int32_t ___1_maxNum, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Random ran = new Random();
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_0 = (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8*)il2cpp_codegen_object_new(Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC(L_0, NULL);
		// return ran.Next(minNum, maxNum);
		int32_t L_1 = ___0_minNum;
		int32_t L_2 = ___1_maxNum;
		NullCheck(L_0);
		int32_t L_3;
		L_3 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6 /* System.Int32 System.Random::Next(System.Int32,System.Int32) */, L_0, L_1, L_2);
		return L_3;
	}
}
// System.Collections.Generic.IList`1<System.Collections.Generic.IList`1<System.Int32>> Tools::MergeSimilarItems(System.Int32[][],System.Int32[][])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Tools_MergeSimilarItems_mFF0E34BDE0C42BCFE7D1B805660FD270F488C344 (Tools_t3DF42EB905CE903A075617859FA36803BEC507C4* __this, Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___0_items1, Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___1_items2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICollection_1_tC5372778958BA5852D51B60DE91458957B103012_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_t702400094DFC0F9AF0893F00166C2C1632C01819_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t0003EC9F1922ECBB54EB7E71B85E13FBC8357DD6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Sort_m0325E504A9F068571CDFAC2F69891902A1A7A263_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m34392E0322B2071E67CE2DE1218585334AF12271_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3CMergeSimilarItemsU3Eb__2_0_mA38BB2AED2FAE883FE0A20D946ED768404156C73_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_2 = NULL;
	int32_t V_3 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_4 = NULL;
	RuntimeObject* V_5 = NULL;
	int32_t V_6 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_7 = NULL;
	RuntimeObject* V_8 = NULL;
	KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189 V_9;
	memset((&V_9), 0, sizeof(V_9));
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* G_B16_0 = NULL;
	List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77* G_B16_1 = NULL;
	Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* G_B15_0 = NULL;
	List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77* G_B15_1 = NULL;
	{
		// IDictionary<int, int> dictionary = new Dictionary<int, int>();
		Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180* L_0 = (Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180*)il2cpp_codegen_object_new(Dictionary_2_tABE19B9C5C52F1DE14F0D3287B2696E7D7419180_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F(L_0, Dictionary_2__ctor_m712893C2C48C47CCAFAD85A865C702E8D3D2B71F_RuntimeMethod_var);
		V_0 = L_0;
		// foreach (int[] v in items1)
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_1 = ___0_items1;
		V_2 = L_1;
		V_3 = 0;
		goto IL_0041;
	}

IL_000c:
	{
		// foreach (int[] v in items1)
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_2 = V_2;
		int32_t L_3 = V_3;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_4 = L_5;
		// dictionary.TryAdd(v[0], 0);
		RuntimeObject* L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_4;
		NullCheck(L_7);
		int32_t L_8 = 0;
		int32_t L_9 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		bool L_10;
		L_10 = CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D(L_6, L_9, 0, CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_RuntimeMethod_var);
		// dictionary[v[0]] += v[1];
		RuntimeObject* L_11 = V_0;
		V_5 = L_11;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = V_4;
		NullCheck(L_12);
		int32_t L_13 = 0;
		int32_t L_14 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_6 = L_14;
		RuntimeObject* L_15 = V_5;
		int32_t L_16 = V_6;
		RuntimeObject* L_17 = V_5;
		int32_t L_18 = V_6;
		NullCheck(L_17);
		int32_t L_19;
		L_19 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(0 /* TValue System.Collections.Generic.IDictionary`2<System.Int32,System.Int32>::get_Item(TKey) */, IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var, L_17, L_18);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_20 = V_4;
		NullCheck(L_20);
		int32_t L_21 = 1;
		int32_t L_22 = (L_20)->GetAt(static_cast<il2cpp_array_size_t>(L_21));
		NullCheck(L_15);
		InterfaceActionInvoker2< int32_t, int32_t >::Invoke(1 /* System.Void System.Collections.Generic.IDictionary`2<System.Int32,System.Int32>::set_Item(TKey,TValue) */, IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var, L_15, L_16, ((int32_t)il2cpp_codegen_add(L_19, L_22)));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0041:
	{
		// foreach (int[] v in items1)
		int32_t L_24 = V_3;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_25 = V_2;
		NullCheck(L_25);
		if ((((int32_t)L_24) < ((int32_t)((int32_t)(((RuntimeArray*)L_25)->max_length)))))
		{
			goto IL_000c;
		}
	}
	{
		// foreach (int[] v in items2)
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_26 = ___1_items2;
		V_2 = L_26;
		V_3 = 0;
		goto IL_0082;
	}

IL_004d:
	{
		// foreach (int[] v in items2)
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_27 = V_2;
		int32_t L_28 = V_3;
		NullCheck(L_27);
		int32_t L_29 = L_28;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_30 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_29));
		V_7 = L_30;
		// dictionary.TryAdd(v[0], 0);
		RuntimeObject* L_31 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_32 = V_7;
		NullCheck(L_32);
		int32_t L_33 = 0;
		int32_t L_34 = (L_32)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		bool L_35;
		L_35 = CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D(L_31, L_34, 0, CollectionExtensions_TryAdd_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94D0B905A72A2D75A9ECA4774FF6445A831F4A6D_RuntimeMethod_var);
		// dictionary[v[0]] += v[1];
		RuntimeObject* L_36 = V_0;
		V_5 = L_36;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_7;
		NullCheck(L_37);
		int32_t L_38 = 0;
		int32_t L_39 = (L_37)->GetAt(static_cast<il2cpp_array_size_t>(L_38));
		V_6 = L_39;
		RuntimeObject* L_40 = V_5;
		int32_t L_41 = V_6;
		RuntimeObject* L_42 = V_5;
		int32_t L_43 = V_6;
		NullCheck(L_42);
		int32_t L_44;
		L_44 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(0 /* TValue System.Collections.Generic.IDictionary`2<System.Int32,System.Int32>::get_Item(TKey) */, IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var, L_42, L_43);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_45 = V_7;
		NullCheck(L_45);
		int32_t L_46 = 1;
		int32_t L_47 = (L_45)->GetAt(static_cast<il2cpp_array_size_t>(L_46));
		NullCheck(L_40);
		InterfaceActionInvoker2< int32_t, int32_t >::Invoke(1 /* System.Void System.Collections.Generic.IDictionary`2<System.Int32,System.Int32>::set_Item(TKey,TValue) */, IDictionary_2_tD7429CE1A1D78F0C391515DA897DD0EB3091757E_il2cpp_TypeInfo_var, L_40, L_41, ((int32_t)il2cpp_codegen_add(L_44, L_47)));
		int32_t L_48 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_48, 1));
	}

IL_0082:
	{
		// foreach (int[] v in items2)
		int32_t L_49 = V_3;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_50 = V_2;
		NullCheck(L_50);
		if ((((int32_t)L_49) < ((int32_t)((int32_t)(((RuntimeArray*)L_50)->max_length)))))
		{
			goto IL_004d;
		}
	}
	{
		// IList<IList<int>> res = new List<IList<int>>();
		List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77* L_51 = (List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77*)il2cpp_codegen_object_new(List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_il2cpp_TypeInfo_var);
		NullCheck(L_51);
		List_1__ctor_m34392E0322B2071E67CE2DE1218585334AF12271(L_51, List_1__ctor_m34392E0322B2071E67CE2DE1218585334AF12271_RuntimeMethod_var);
		V_1 = L_51;
		// foreach (KeyValuePair<int, int> kv in dictionary)
		RuntimeObject* L_52 = V_0;
		NullCheck(L_52);
		RuntimeObject* L_53;
		L_53 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0 /* System.Collections.Generic.IEnumerator`1<T> System.Collections.Generic.IEnumerable`1<System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>>::GetEnumerator() */, IEnumerable_1_t702400094DFC0F9AF0893F00166C2C1632C01819_il2cpp_TypeInfo_var, L_52);
		V_8 = L_53;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d9:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_54 = V_8;
					if (!L_54)
					{
						goto IL_00e4;
					}
				}
				{
					RuntimeObject* L_55 = V_8;
					NullCheck(L_55);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_55);
				}

IL_00e4:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_00ce_1;
			}

IL_0098_1:
			{
				// foreach (KeyValuePair<int, int> kv in dictionary)
				RuntimeObject* L_56 = V_8;
				NullCheck(L_56);
				KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189 L_57;
				L_57 = InterfaceFuncInvoker0< KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189 >::Invoke(0 /* T System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>>::get_Current() */, IEnumerator_1_t0003EC9F1922ECBB54EB7E71B85E13FBC8357DD6_il2cpp_TypeInfo_var, L_56);
				V_9 = L_57;
				// int k = kv.Key, v = kv.Value;
				int32_t L_58;
				L_58 = KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_inline((&V_9), KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_RuntimeMethod_var);
				V_10 = L_58;
				// int k = kv.Key, v = kv.Value;
				int32_t L_59;
				L_59 = KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_inline((&V_9), KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_RuntimeMethod_var);
				V_11 = L_59;
				// res.Add(new List<int> { k, v });
				RuntimeObject* L_60 = V_1;
				List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_61 = (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*)il2cpp_codegen_object_new(List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
				NullCheck(L_61);
				List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8(L_61, List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
				List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_62 = L_61;
				int32_t L_63 = V_10;
				NullCheck(L_62);
				List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline(L_62, L_63, List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
				List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_64 = L_62;
				int32_t L_65 = V_11;
				NullCheck(L_64);
				List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline(L_64, L_65, List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
				NullCheck(L_60);
				InterfaceActionInvoker1< RuntimeObject* >::Invoke(2 /* System.Void System.Collections.Generic.ICollection`1<System.Collections.Generic.IList`1<System.Int32>>::Add(T) */, ICollection_1_tC5372778958BA5852D51B60DE91458957B103012_il2cpp_TypeInfo_var, L_60, L_64);
			}

IL_00ce_1:
			{
				// foreach (KeyValuePair<int, int> kv in dictionary)
				RuntimeObject* L_66 = V_8;
				NullCheck(L_66);
				bool L_67;
				L_67 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_66);
				if (L_67)
				{
					goto IL_0098_1;
				}
			}
			{
				goto IL_00e5;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00e5:
	{
		// ((List<IList<int>>)res).Sort((a, b) => a[0] - b[0]);
		RuntimeObject* L_68 = V_1;
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var);
		Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* L_69 = ((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1;
		Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* L_70 = L_69;
		G_B15_0 = L_70;
		G_B15_1 = ((List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77*)CastclassClass((RuntimeObject*)L_68, List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_il2cpp_TypeInfo_var));
		if (L_70)
		{
			G_B16_0 = L_70;
			G_B16_1 = ((List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77*)CastclassClass((RuntimeObject*)L_68, List_1_t25BDB544A77A1D130FCE30580D4CD89E38C9CC77_il2cpp_TypeInfo_var));
			goto IL_010a;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var);
		U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* L_71 = ((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9_0;
		Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* L_72 = (Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E*)il2cpp_codegen_object_new(Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E_il2cpp_TypeInfo_var);
		NullCheck(L_72);
		Comparison_1__ctor_m2968B906243D4C6719E52333B828FE2513B8D9E0(L_72, L_71, (intptr_t)((void*)U3CU3Ec_U3CMergeSimilarItemsU3Eb__2_0_mA38BB2AED2FAE883FE0A20D946ED768404156C73_RuntimeMethod_var), NULL);
		Comparison_1_t3D9D27E62D8EFC94A5A467C03B038523229CE14E* L_73 = L_72;
		((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1 = L_73;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1), (void*)L_73);
		G_B16_0 = L_73;
		G_B16_1 = G_B15_1;
	}

IL_010a:
	{
		NullCheck(G_B16_1);
		List_1_Sort_m0325E504A9F068571CDFAC2F69891902A1A7A263(G_B16_1, G_B16_0, List_1_Sort_m0325E504A9F068571CDFAC2F69891902A1A7A263_RuntimeMethod_var);
		// return res;
		RuntimeObject* L_74 = V_1;
		return L_74;
	}
}
// System.Collections.Generic.List`1<System.Int32> Tools::GenerateRandomUniqueData(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* Tools_GenerateRandomUniqueData_m49423BF22EDBF1C0EC492FB427AF60F1CD0E99BF (int32_t ___0_minValue, int32_t ___1_maxValue, int32_t ___2_count, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* V_0 = NULL;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* V_1 = NULL;
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	{
		// if (count > (maxValue - minValue + 1) || count <= 0)
		int32_t L_0 = ___2_count;
		int32_t L_1 = ___1_maxValue;
		int32_t L_2 = ___0_minValue;
		if ((((int32_t)L_0) > ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_1, L_2)), 1)))))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_3 = ___2_count;
		if ((((int32_t)L_3) > ((int32_t)0)))
		{
			goto IL_0017;
		}
	}

IL_000c:
	{
		// throw new ArgumentException("Invalid count or range");
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		NullCheck(L_4);
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral4D2404A81DE320C8F8813DF7EA8F5B10E6FAD2EB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Tools_GenerateRandomUniqueData_m49423BF22EDBF1C0EC492FB427AF60F1CD0E99BF_RuntimeMethod_var)));
	}

IL_0017:
	{
		// List<int> data = Enumerable.Range(minValue, maxValue - minValue + 1).ToList();
		int32_t L_5 = ___0_minValue;
		int32_t L_6 = ___1_maxValue;
		int32_t L_7 = ___0_minValue;
		RuntimeObject* L_8;
		L_8 = Enumerable_Range_m4FB9BBBA09BEF5177C13506DB385CF4467C15FD8(L_5, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1)), NULL);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_9;
		L_9 = Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC(L_8, Enumerable_ToList_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3E9A8F467117CBA5D91E50BC524DEA85E532EAAC_RuntimeMethod_var);
		V_0 = L_9;
		// List<int> randomData = new List<int>();
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_10 = (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*)il2cpp_codegen_object_new(List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8(L_10, List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		V_1 = L_10;
		// Random random = new Random();
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_11 = (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8*)il2cpp_codegen_object_new(Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC(L_11, NULL);
		V_2 = L_11;
		// for (int i = 0; i < count; i++)
		V_3 = 0;
		goto IL_0060;
	}

IL_0038:
	{
		// int index = random.Next(data.Count);
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_12 = V_2;
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_13 = V_0;
		NullCheck(L_13);
		int32_t L_14;
		L_14 = List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_inline(L_13, List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		NullCheck(L_12);
		int32_t L_15;
		L_15 = VirtualFuncInvoker1< int32_t, int32_t >::Invoke(7 /* System.Int32 System.Random::Next(System.Int32) */, L_12, L_14);
		V_4 = L_15;
		// randomData.Add(data[index]);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_16 = V_1;
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_17 = V_0;
		int32_t L_18 = V_4;
		NullCheck(L_17);
		int32_t L_19;
		L_19 = List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D(L_17, L_18, List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		NullCheck(L_16);
		List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline(L_16, L_19, List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
		// data.RemoveAt(index);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_20 = V_0;
		int32_t L_21 = V_4;
		NullCheck(L_20);
		List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004(L_20, L_21, List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_22 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_0060:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_23 = V_3;
		int32_t L_24 = ___2_count;
		if ((((int32_t)L_23) < ((int32_t)L_24)))
		{
			goto IL_0038;
		}
	}
	{
		// return randomData;
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_25 = V_1;
		return L_25;
	}
}
// System.Void Tools::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tools__ctor_m438DB9E9B6A62C7A0F363A67C770E1833DD160AD (Tools_t3DF42EB905CE903A075617859FA36803BEC507C4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseManager_1__ctor_m783192CA846185C692F3A4D5EF88408EBD62E85E_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		BaseManager_1__ctor_m783192CA846185C692F3A4D5EF88408EBD62E85E(__this, BaseManager_1__ctor_m783192CA846185C692F3A4D5EF88408EBD62E85E_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Tools/<>c::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_mA404F052FE7AD91C575BD9F28C89A163AD119E95 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* L_0 = (U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290*)il2cpp_codegen_object_new(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CU3Ec__ctor_mCE0F9ED4FDCC9606AAE9870169BDCA3CB96A940A(L_0, NULL);
		((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290_il2cpp_TypeInfo_var))->___U3CU3E9_0), (void*)L_0);
		return;
	}
}
// System.Void Tools/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mCE0F9ED4FDCC9606AAE9870169BDCA3CB96A940A (U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Int32 Tools/<>c::<MergeSimilarItems>b__2_0(System.Collections.Generic.IList`1<System.Int32>,System.Collections.Generic.IList`1<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t U3CU3Ec_U3CMergeSimilarItemsU3Eb__2_0_mA38BB2AED2FAE883FE0A20D946ED768404156C73 (U3CU3Ec_t80F958A7E7D0A297DDCA29442C16054E301BF290* __this, RuntimeObject* ___0_a, RuntimeObject* ___1_b, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IList_1_tFB8BE2ED9A601C1259EAB8D73D1B3E96EA321FA1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// ((List<IList<int>>)res).Sort((a, b) => a[0] - b[0]);
		RuntimeObject* L_0 = ___0_a;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(0 /* T System.Collections.Generic.IList`1<System.Int32>::get_Item(System.Int32) */, IList_1_tFB8BE2ED9A601C1259EAB8D73D1B3E96EA321FA1_il2cpp_TypeInfo_var, L_0, 0);
		RuntimeObject* L_2 = ___1_b;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(0 /* T System.Collections.Generic.IList`1<System.Int32>::get_Item(System.Int32) */, IList_1_tFB8BE2ED9A601C1259EAB8D73D1B3E96EA321FA1_il2cpp_TypeInfo_var, L_2, 0);
		return ((int32_t)il2cpp_codegen_subtract(L_1, L_3));
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Conversion methods for marshalling of: StuctsCom.SPlayerData
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_pinvoke(const SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6& unmarshaled, SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_pinvoke& marshaled)
{
	marshaled.___name_0 = il2cpp_codegen_marshal_string(unmarshaled.___name_0);
	marshaled.___playerScore_1 = unmarshaled.___playerScore_1;
}
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_pinvoke_back(const SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_pinvoke& marshaled, SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6& unmarshaled)
{
	unmarshaled.___name_0 = il2cpp_codegen_marshal_string_result(marshaled.___name_0);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___name_0), (void*)il2cpp_codegen_marshal_string_result(marshaled.___name_0));
	int32_t unmarshaledplayerScore_temp_1 = 0;
	unmarshaledplayerScore_temp_1 = marshaled.___playerScore_1;
	unmarshaled.___playerScore_1 = unmarshaledplayerScore_temp_1;
}
// Conversion method for clean up from marshalling of: StuctsCom.SPlayerData
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_pinvoke_cleanup(SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_marshal_free(marshaled.___name_0);
	marshaled.___name_0 = NULL;
}
// Conversion methods for marshalling of: StuctsCom.SPlayerData
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_com(const SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6& unmarshaled, SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_com& marshaled)
{
	marshaled.___name_0 = il2cpp_codegen_marshal_bstring(unmarshaled.___name_0);
	marshaled.___playerScore_1 = unmarshaled.___playerScore_1;
}
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_com_back(const SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_com& marshaled, SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6& unmarshaled)
{
	unmarshaled.___name_0 = il2cpp_codegen_marshal_bstring_result(marshaled.___name_0);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___name_0), (void*)il2cpp_codegen_marshal_bstring_result(marshaled.___name_0));
	int32_t unmarshaledplayerScore_temp_1 = 0;
	unmarshaledplayerScore_temp_1 = marshaled.___playerScore_1;
	unmarshaled.___playerScore_1 = unmarshaledplayerScore_temp_1;
}
// Conversion method for clean up from marshalling of: StuctsCom.SPlayerData
IL2CPP_EXTERN_C void SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshal_com_cleanup(SPlayerData_tA3A60B7CB4E0EF223A7906AC452599DDF56E6ED6_marshaled_com& marshaled)
{
	il2cpp_codegen_marshal_free_bstring(marshaled.___name_0);
	marshaled.___name_0 = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityAction_Invoke_m5CB9EE17CCDF64D00DE5D96DF3553CDB20D66F70_inline (UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Act_Invoke_m19DC4D84AA3B1FB296B07BE96F7172DDF724C2E6_inline (Act_t0F1646F209E123BCA3D1D901B734CE7E2858F8BE* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TimerHandler_Invoke_mCA7878DCFD0EC0AF92417BF723B88B61FDE1CED9_inline (TimerHandler_tCB1B627DCDDF8E4D11BD660F5886246961BE7F23* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline (EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* __this, const RuntimeMethod* method) 
{
	{
		// get { return m_CurrentSelected; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___m_CurrentSelected_10;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* Image_get_sprite_mB2AA377708722E100574F6F75BC102513BB3BCB1_inline (Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* __this, const RuntimeMethod* method) 
{
	{
		// get { return m_Sprite; }
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_0 = __this->___m_Sprite_38;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_FloorToInt_m2A39AE881CAEE6B6A4B3BFEF9CA1ED40625F5AB7_inline (float ___0_f, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		float L_0 = ___0_f;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = floor(((double)L_0));
		V_0 = il2cpp_codegen_cast_double_to_int<int32_t>(L_1);
		goto IL_000c;
	}

IL_000c:
	{
		int32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = (int32_t)__this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)__this->____items_1;
		V_0 = L_1;
		int32_t L_2 = (int32_t)__this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = (int32_t)__this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityAction_1_Invoke_m777839BF9CB9F96B081106B47202D06FB35326CA_gshared_inline (UnityAction_1_t9C30BCD020745BF400CBACF22C6F34ADBA2DDA6A* __this, RuntimeObject* ___0_arg0, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_arg0, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = (int32_t)__this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		if (!true)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_1 = (int32_t)__this->____size_2;
		V_0 = L_1;
		__this->____size_2 = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)__this->____items_1;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_0035:
	{
		__this->____size_2 = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m1412A508E37D95E08FB60E8976FB75714BE934C1_gshared_inline (Enumerator_tC17DB73F53085145D57EE2A8168426239B0B569D* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = (RuntimeObject*)__this->____currentValue_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline (const RuntimeMethod* method) 
{
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ((EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = (int32_t)__this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)__this->____items_1;
		V_0 = L_1;
		int32_t L_2 = (int32_t)__this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = V_0;
		int32_t L_7 = V_1;
		int32_t L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (int32_t)L_8);
		return;
	}

IL_0034:
	{
		int32_t L_9 = ___0_item;
		((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = (int32_t)__this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_m5A886C4B3E54DEA04D456E49D7FB92A4545FCD8F_gshared_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = (int32_t)__this->___key_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Value_m83DA000FF3605DAD9160D02FB36863DF77DB468A_gshared_inline (KeyValuePair_2_tA6BE5EEAC56CB97CB7383FCC3CC6C84FAF129189* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = (int32_t)__this->___value_1;
		return L_0;
	}
}
