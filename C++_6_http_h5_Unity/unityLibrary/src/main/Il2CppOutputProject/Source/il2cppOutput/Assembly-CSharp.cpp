#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


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

// System.Comparison`1<UnityEngine.EventSystems.RaycastResult>
struct Comparison_1_t9FCAC8C8CE160A96C5AAD2DE1D353DCE8A2FEEFC;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseInputModule>
struct List_1_tA5BDE435C735A082941CD33D212F97F4AE9FA55F;
// System.Collections.Generic.List`1<UnityEngine.CanvasGroup>
struct List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventSystem>
struct List_1_tF2FE88545EFEC788CAAE6C74EC2F78E937FCCAC3;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// UnityEngine.UI.Selectable[]
struct SelectableU5BU5D_t4160E135F02A40F75A63F787D36F31FEC6FE91A9;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// UnityEngine.UI.AnimationTriggers
struct AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F;
// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707;
// UnityEngine.UI.FontData
struct FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// UnityEngine.UI.Image
struct Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E;
// MainScene
struct MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// ProgressBar
struct ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712;
// UnityEngine.UI.Slider
struct Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F;
// SpinnerController
struct SpinnerController_tFFE28A65514003EFD815E8D82BF0F540878317C8;
// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99;
// StartScene
struct StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670;
// System.String
struct String_t;
// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62;
// UnityEngine.TextGenerator
struct TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// MainScene/<SpinAnimation>d__20
struct U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// UnityEngine.UI.Slider/SliderEvent
struct SliderEvent_t92A82EF6C62E15AF92B640FE2D960E877E8C6555;

IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral2B164EB9D02E814EE37F29993945449F113A63BA;
IL2CPP_EXTERN_C String_t* _stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63;
IL2CPP_EXTERN_C String_t* _stringLiteral491173E614C40124689C06F4F6654A982066BEEF;
IL2CPP_EXTERN_C String_t* _stringLiteral526BE583C58C4E8100CB4E6693A4BF128276F5EF;
IL2CPP_EXTERN_C String_t* _stringLiteral698239B5BEAE30EC6985EBFA3F1372FD20951949;
IL2CPP_EXTERN_C String_t* _stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743;
IL2CPP_EXTERN_C String_t* _stringLiteral6D4D6B996C6E6D24F331B554B9FF55B6E0028284;
IL2CPP_EXTERN_C String_t* _stringLiteral793124C2C69F7C5AD956B8E7C24C95DFD06780A5;
IL2CPP_EXTERN_C String_t* _stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E;
IL2CPP_EXTERN_C String_t* _stringLiteral884820433266E121D9AF505AF4DE98B3BA081DC8;
IL2CPP_EXTERN_C String_t* _stringLiteralC0D1E019D3BC190AF31B69929DEBBD8DF9E93926;
IL2CPP_EXTERN_C String_t* _stringLiteralC815B3C4337048311EC4F9295DCA65F216869AD2;
IL2CPP_EXTERN_C String_t* _stringLiteralE64636929F4E535CE1963A7AFA0E20B5F6D46EAC;
IL2CPP_EXTERN_C const RuntimeMethod* U3CSpinAnimationU3Ed__20_System_Collections_IEnumerator_Reset_mDCC27E477B437217E43F1E086C34B153D2EAE783_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


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

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
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

// MainScene/<SpinAnimation>d__20
struct U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA  : public RuntimeObject
{
	// System.Int32 MainScene/<SpinAnimation>d__20::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object MainScene/<SpinAnimation>d__20::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// MainScene MainScene/<SpinAnimation>d__20::<>4__this
	MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* ___U3CU3E4__this_2;
	// System.Single MainScene/<SpinAnimation>d__20::<rotationDuration>5__2
	float ___U3CrotationDurationU3E5__2_3;
	// System.Single MainScene/<SpinAnimation>d__20::<fastRotationDuration>5__3
	float ___U3CfastRotationDurationU3E5__3_4;
	// System.Int32 MainScene/<SpinAnimation>d__20::<targetItem>5__4
	int32_t ___U3CtargetItemU3E5__4_5;
	// System.Single MainScene/<SpinAnimation>d__20::<targetRotation>5__5
	float ___U3CtargetRotationU3E5__5_6;
	// System.Single MainScene/<SpinAnimation>d__20::<startRotation>5__6
	float ___U3CstartRotationU3E5__6_7;
	// System.Single MainScene/<SpinAnimation>d__20::<targetRotationAmount>5__7
	float ___U3CtargetRotationAmountU3E5__7_8;
	// System.Single MainScene/<SpinAnimation>d__20::<elapsedRotationTime>5__8
	float ___U3CelapsedRotationTimeU3E5__8_9;
	// System.Single MainScene/<SpinAnimation>d__20::<elapsedFastRotationTime>5__9
	float ___U3CelapsedFastRotationTimeU3E5__9_10;
	// System.Single MainScene/<SpinAnimation>d__20::<finalRotation>5__10
	float ___U3CfinalRotationU3E5__10_11;
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
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

// UnityEngine.DrivenRectTransformTracker
struct DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1 
{
	union
	{
		struct
		{
		};
		uint8_t DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1__padding[1];
	};
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

// UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C 
{
	// UnityEngine.UI.Navigation/Mode UnityEngine.UI.Navigation::m_Mode
	int32_t ___m_Mode_0;
	// System.Boolean UnityEngine.UI.Navigation::m_WrapAround
	bool ___m_WrapAround_1;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnUp
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnDown
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnLeft
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnRight
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_pinvoke
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for COM marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_com
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};

// UnityEngine.Quaternion
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 
{
	// System.Single UnityEngine.Quaternion::x
	float ___x_0;
	// System.Single UnityEngine.Quaternion::y
	float ___y_1;
	// System.Single UnityEngine.Quaternion::z
	float ___z_2;
	// System.Single UnityEngine.Quaternion::w
	float ___w_3;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD 
{
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_HighlightedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_PressedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_SelectedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_DisabledSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_pinvoke
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for COM marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_com
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};

// UnityEngine.Vector2
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	// System.Single UnityEngine.Vector2::x
	float ___x_0;
	// System.Single UnityEngine.Vector2::y
	float ___y_1;
};

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	// System.Single UnityEngine.Vector3::x
	float ___x_2;
	// System.Single UnityEngine.Vector3::y
	float ___y_3;
	// System.Single UnityEngine.Vector3::z
	float ___z_4;
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

// UnityEngine.UI.ColorBlock
struct ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 
{
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_NormalColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_NormalColor_0;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_HighlightedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_HighlightedColor_1;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_PressedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_PressedColor_2;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_SelectedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_SelectedColor_3;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_DisabledColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_DisabledColor_4;
	// System.Single UnityEngine.UI.ColorBlock::m_ColorMultiplier
	float ___m_ColorMultiplier_5;
	// System.Single UnityEngine.UI.ColorBlock::m_FadeDuration
	float ___m_FadeDuration_6;
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

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
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

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// MainScene
struct MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.GameObject MainScene::PopHelp
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___PopHelp_4;
	// UnityEngine.GameObject MainScene::PopResult
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___PopResult_5;
	// UnityEngine.GameObject MainScene::spinner_bg
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___spinner_bg_6;
	// UnityEngine.GameObject MainScene::spinner
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___spinner_7;
	// UnityEngine.GameObject MainScene::ani_tx
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___ani_tx_8;
	// UnityEngine.UI.Text MainScene::text_score
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___text_score_9;
	// System.Boolean MainScene::isRotating
	bool ___isRotating_10;
	// System.Int32 MainScene::score
	int32_t ___score_11;
	// System.Object MainScene::<SceneManage>k__BackingField
	RuntimeObject* ___U3CSceneManageU3Ek__BackingField_12;
};

// ProgressBar
struct ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Slider ProgressBar::slider
	Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* ___slider_4;
	// System.Single ProgressBar::fillSpeed
	float ___fillSpeed_5;
	// System.Single ProgressBar::targetProgress
	float ___targetProgress_6;
};

// SpinnerController
struct SpinnerController_tFFE28A65514003EFD815E8D82BF0F540878317C8  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single SpinnerController::rotationSpeed
	float ___rotationSpeed_4;
};

// StartScene
struct StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.GameObject StartScene::PopStart
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___PopStart_4;
	// UnityEngine.GameObject StartScene::PopLoad
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___PopLoad_5;
	// ProgressBar StartScene::progressBar
	ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* ___progressBar_6;
	// System.Single StartScene::updateInterval
	float ___updateInterval_7;
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

// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Boolean UnityEngine.UI.Selectable::m_EnableCalled
	bool ___m_EnableCalled_6;
	// UnityEngine.UI.Navigation UnityEngine.UI.Selectable::m_Navigation
	Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C ___m_Navigation_7;
	// UnityEngine.UI.Selectable/Transition UnityEngine.UI.Selectable::m_Transition
	int32_t ___m_Transition_8;
	// UnityEngine.UI.ColorBlock UnityEngine.UI.Selectable::m_Colors
	ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 ___m_Colors_9;
	// UnityEngine.UI.SpriteState UnityEngine.UI.Selectable::m_SpriteState
	SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD ___m_SpriteState_10;
	// UnityEngine.UI.AnimationTriggers UnityEngine.UI.Selectable::m_AnimationTriggers
	AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074* ___m_AnimationTriggers_11;
	// System.Boolean UnityEngine.UI.Selectable::m_Interactable
	bool ___m_Interactable_12;
	// UnityEngine.UI.Graphic UnityEngine.UI.Selectable::m_TargetGraphic
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___m_TargetGraphic_13;
	// System.Boolean UnityEngine.UI.Selectable::m_GroupsAllowInteraction
	bool ___m_GroupsAllowInteraction_14;
	// System.Int32 UnityEngine.UI.Selectable::m_CurrentIndex
	int32_t ___m_CurrentIndex_15;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerInside>k__BackingField
	bool ___U3CisPointerInsideU3Ek__BackingField_16;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerDown>k__BackingField
	bool ___U3CisPointerDownU3Ek__BackingField_17;
	// System.Boolean UnityEngine.UI.Selectable::<hasSelection>k__BackingField
	bool ___U3ChasSelectionU3Ek__BackingField_18;
	// System.Collections.Generic.List`1<UnityEngine.CanvasGroup> UnityEngine.UI.Selectable::m_CanvasGroupCache
	List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35* ___m_CanvasGroupCache_19;
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

// UnityEngine.UI.Slider
struct Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F  : public Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712
{
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_FillRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_FillRect_20;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_HandleRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_HandleRect_21;
	// UnityEngine.UI.Slider/Direction UnityEngine.UI.Slider::m_Direction
	int32_t ___m_Direction_22;
	// System.Single UnityEngine.UI.Slider::m_MinValue
	float ___m_MinValue_23;
	// System.Single UnityEngine.UI.Slider::m_MaxValue
	float ___m_MaxValue_24;
	// System.Boolean UnityEngine.UI.Slider::m_WholeNumbers
	bool ___m_WholeNumbers_25;
	// System.Single UnityEngine.UI.Slider::m_Value
	float ___m_Value_26;
	// UnityEngine.UI.Slider/SliderEvent UnityEngine.UI.Slider::m_OnValueChanged
	SliderEvent_t92A82EF6C62E15AF92B640FE2D960E877E8C6555* ___m_OnValueChanged_27;
	// UnityEngine.UI.Image UnityEngine.UI.Slider::m_FillImage
	Image_tBC1D03F63BF71132E9A5E472B8742F172A011E7E* ___m_FillImage_28;
	// UnityEngine.Transform UnityEngine.UI.Slider::m_FillTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_FillTransform_29;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_FillContainerRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_FillContainerRect_30;
	// UnityEngine.Transform UnityEngine.UI.Slider::m_HandleTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_HandleTransform_31;
	// UnityEngine.RectTransform UnityEngine.UI.Slider::m_HandleContainerRect
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_HandleContainerRect_32;
	// UnityEngine.Vector2 UnityEngine.UI.Slider::m_Offset
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Offset_33;
	// UnityEngine.DrivenRectTransformTracker UnityEngine.UI.Slider::m_Tracker
	DrivenRectTransformTracker_tFB0706C933E3C68E4F377C204FCEEF091F1EE0B1 ___m_Tracker_34;
	// System.Boolean UnityEngine.UI.Slider::m_DelayedUpdateVisuals
	bool ___m_DelayedUpdateVisuals_35;
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

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// MainScene/<SpinAnimation>d__20

// MainScene/<SpinAnimation>d__20

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Int32

// System.Int32

// UnityEngine.Quaternion
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_StaticFields
{
	// UnityEngine.Quaternion UnityEngine.Quaternion::identityQuaternion
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___identityQuaternion_4;
};

// UnityEngine.Quaternion

// System.Single

// System.Single

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	// UnityEngine.Vector3 UnityEngine.Vector3::zeroVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector_5;
	// UnityEngine.Vector3 UnityEngine.Vector3::oneVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector_6;
	// UnityEngine.Vector3 UnityEngine.Vector3::upVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector_7;
	// UnityEngine.Vector3 UnityEngine.Vector3::downVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector_8;
	// UnityEngine.Vector3 UnityEngine.Vector3::leftVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector_9;
	// UnityEngine.Vector3 UnityEngine.Vector3::rightVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector_10;
	// UnityEngine.Vector3 UnityEngine.Vector3::forwardVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector_11;
	// UnityEngine.Vector3 UnityEngine.Vector3::backVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector_12;
	// UnityEngine.Vector3 UnityEngine.Vector3::positiveInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector_13;
	// UnityEngine.Vector3 UnityEngine.Vector3::negativeInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector_14;
};

// UnityEngine.Vector3

// System.Void

// System.Void

// UnityEngine.Coroutine

// UnityEngine.Coroutine

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// System.NotSupportedException

// System.NotSupportedException

// UnityEngine.Transform

// UnityEngine.Transform

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// MainScene

// MainScene

// ProgressBar

// ProgressBar

// SpinnerController

// SpinnerController

// StartScene

// StartScene

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

// UnityEngine.UI.Slider

// UnityEngine.UI.Slider

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



// System.Void MainScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_InintView_mB9304CA045ECC712937A85EB7AAC410F529FB263 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) ;
// System.Void MainScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_UpdateView_m4BB940353941B43DC6B75401F85FD529BF092081 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.EventSystem::get_current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016 (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::get_currentSelectedGameObject()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline (EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.Object::get_name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Equality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::StopCoroutine(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_StopCoroutine_m1DA0B9343DCDB53221A6CD707CBF0827A6FFF17F (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, const RuntimeMethod* method) ;
// System.Void MainScene::StopAnim()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_StopAnim_m786F7A2F00F120D025F160C8A25619552CD24CB5 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_m10C4B693B96175C42B0FD00911E072701C220DB4 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, const RuntimeMethod* method) ;
// System.Void UnityEngine.SceneManagement.SceneManager::LoadScene(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E (String_t* ___0_sceneName, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::SetActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void MainScene/<SpinAnimation>d__20::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSpinAnimationU3Ed__20__ctor_m95F3CEB6CE07395785CEDE17E6FEB4F36A919BD8 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Random::Range(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Random_Range_m6763D9767F033357F88B6637F048F4ACA4123B68 (int32_t ___0_minInclusive, int32_t ___1_maxExclusive, const RuntimeMethod* method) ;
// System.Single MainScene::GetTargetRotationForItem(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float MainScene_GetTargetRotationForItem_mEE80656AA86571D55C36D0AB058994322A6E9D5E (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, int32_t ___0_itemNumber, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.GameObject::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Transform::get_rotation()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Quaternion::get_eulerAngles()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Quaternion_get_eulerAngles_m2DB5158B5C3A71FD60FC8A6EE43D3AAA1CFED122_inline (Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Time::get_deltaTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865 (const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_forward()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline (const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::Rotate(UnityEngine.Vector3,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_axis, float ___1_angle, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Quaternion::Euler(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Quaternion_Euler_m9262AB29E3E9CE94EF71051F38A28E82AEC73F90_inline (float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_rotation(UnityEngine.Quaternion)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::Invoke(System.String,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, float ___1_time, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void System.NotSupportedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
// System.Void ProgressBar::SetProgress(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProgressBar_SetProgress_mB0CA374307C310BD4E66B22D6FC5AD2CDE6D3916 (ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* __this, float ___0_progress, const RuntimeMethod* method) ;
// System.Single UnityEngine.Mathf::Clamp01(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline (float ___0_value, const RuntimeMethod* method) ;
// System.Single UnityEngine.Input::GetAxis(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62 (String_t* ___0_axisName, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.Component::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_up()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) ;
// System.Void StartScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_InintView_mDDA3FF2352E18DD3F1EF769BE0B4F419367F5C1E (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) ;
// System.Void StartScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_UpdateView_mD20779A871A4094C7E2FEDBBE3CF3543E03A4873 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::InvokeRepeating(System.String,System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_InvokeRepeating_mF208501E0E4918F9168BBBA5FC50D8F80D01514D (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, float ___1_time, float ___2_repeatRate, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::CancelInvoke(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_CancelInvoke_m268FFD58AFF64C07FD4C9B9B8B85F58BD86F3A01 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, String_t* ___0_methodName, const RuntimeMethod* method) ;
// System.Void StartScene::ShowMainScreen()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_ShowMainScreen_m1AB56068EDDC6C2B9FDD8A1A85F303192DB922D8 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Quaternion::Internal_ToEulerRad(UnityEngine.Quaternion)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Quaternion_Internal_ToEulerRad_m5BD0EEC543120C320DC77FCCDFD2CE2E6BD3F1A8 (Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___0_rotation, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_Multiply(UnityEngine.Vector3,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Quaternion::Internal_MakePositive(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Quaternion_Internal_MakePositive_m73E2D01920CB0DFE661A55022C129E8617F0C9A8 (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_euler, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector3::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Quaternion::Internal_FromEulerRad(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Quaternion_Internal_FromEulerRad_m66D4475341F53949471E6870FB5C5E4A5E9BA93E (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_euler, const RuntimeMethod* method) ;
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
// System.Object MainScene::get_SceneManage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MainScene_get_SceneManage_m75FDFB896A115705C41097ECF379B576DB389701 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// public object SceneManage { get; private set; }
		RuntimeObject* L_0 = __this->___U3CSceneManageU3Ek__BackingField_12;
		return L_0;
	}
}
// System.Void MainScene::set_SceneManage(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_set_SceneManage_m84BD5E8F80EC13D96805F0B242256DA1C448941B (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		// public object SceneManage { get; private set; }
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CSceneManageU3Ek__BackingField_12 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CSceneManageU3Ek__BackingField_12), (void*)L_0);
		return;
	}
}
// System.Void MainScene::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_Awake_m5BED809110BCD18B3F7BFD4D2F75FBCC5DE11117 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// InintView();
		MainScene_InintView_mB9304CA045ECC712937A85EB7AAC410F529FB263(__this, NULL);
		// }
		return;
	}
}
// System.Void MainScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_InintView_mB9304CA045ECC712937A85EB7AAC410F529FB263 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_OnEnable_m4AF4F09E7169FC679A7950C8C656604E2F9B6927 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// UpdateView();
		MainScene_UpdateView_m4BB940353941B43DC6B75401F85FD529BF092081(__this, NULL);
		// }
		return;
	}
}
// System.Void MainScene::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_Reset_m01020106FBD8A93B2D71E65C2667C3B7A7A212BD (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_Start_mCC35BFF72EE7240E15359FAEBFD97D87AEA78ABC (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// score = 0;
		__this->___score_11 = 0;
		// }
		return;
	}
}
// System.Void MainScene::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_Update_mDB3B22FFB4556E048DF8ADE40D22247102A4107D (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_UpdateView_m4BB940353941B43DC6B75401F85FD529BF092081 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::OnBtnClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_OnBtnClick_mEBEBEB65DE56401216A1166DF7B86C1F534D8A25 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral698239B5BEAE30EC6985EBFA3F1372FD20951949);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral793124C2C69F7C5AD956B8E7C24C95DFD06780A5);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC0D1E019D3BC190AF31B69929DEBBD8DF9E93926);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE64636929F4E535CE1963A7AFA0E20B5F6D46EAC);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// GameObject clickedObject = EventSystem.current.currentSelectedGameObject;
		il2cpp_codegen_runtime_class_init_inline(EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_il2cpp_TypeInfo_var);
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = EventSystem_get_current_mC87C69FB418563DC2A571A10E2F9DB59A6785016(NULL);
		NullCheck(L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline(L_0, NULL);
		// string buttonName = clickedObject.name;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_1, NULL);
		V_0 = L_2;
		String_t* L_3 = V_0;
		bool L_4;
		L_4 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_3, _stringLiteral3F399950F84B21B869AE6BB900116E1133BF2D63, NULL);
		if (L_4)
		{
			goto IL_0045;
		}
	}
	{
		String_t* L_5 = V_0;
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_5, _stringLiteral6C9BE50660D5BCC39431B6D870FF99CBFC8B8743, NULL);
		if (L_6)
		{
			goto IL_006b;
		}
	}
	{
		String_t* L_7 = V_0;
		bool L_8;
		L_8 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_7, _stringLiteral698239B5BEAE30EC6985EBFA3F1372FD20951949, NULL);
		if (L_8)
		{
			goto IL_0076;
		}
	}
	{
		String_t* L_9 = V_0;
		bool L_10;
		L_10 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_9, _stringLiteralE64636929F4E535CE1963A7AFA0E20B5F6D46EAC, NULL);
		if (L_10)
		{
			goto IL_0083;
		}
	}
	{
		return;
	}

IL_0045:
	{
		// if (isRotating)
		bool L_11 = __this->___isRotating_10;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		// StopCoroutine("SpinAnimation");
		MonoBehaviour_StopCoroutine_m1DA0B9343DCDB53221A6CD707CBF0827A6FFF17F(__this, _stringLiteralC0D1E019D3BC190AF31B69929DEBBD8DF9E93926, NULL);
		// StopAnim();
		MainScene_StopAnim_m786F7A2F00F120D025F160C8A25619552CD24CB5(__this, NULL);
	}

IL_005e:
	{
		// StartCoroutine("SpinAnimation");
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_12;
		L_12 = MonoBehaviour_StartCoroutine_m10C4B693B96175C42B0FD00911E072701C220DB4(__this, _stringLiteralC0D1E019D3BC190AF31B69929DEBBD8DF9E93926, NULL);
		// break;
		return;
	}

IL_006b:
	{
		// SceneManager.LoadScene("StartScene");
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(_stringLiteral793124C2C69F7C5AD956B8E7C24C95DFD06780A5, NULL);
		// break;
		return;
	}

IL_0076:
	{
		// PopHelp.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13 = __this->___PopHelp_4;
		NullCheck(L_13);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_13, (bool)1, NULL);
		// break;
		return;
	}

IL_0083:
	{
		// PopHelp.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14 = __this->___PopHelp_4;
		NullCheck(L_14);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_14, (bool)0, NULL);
		// }
		return;
	}
}
// System.Collections.IEnumerator MainScene::SpinAnimation()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MainScene_SpinAnimation_mC0B408C6686A9F0F3FDE2F0FCEBB21C098F64067 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* L_0 = (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA*)il2cpp_codegen_object_new(U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CSpinAnimationU3Ed__20__ctor_m95F3CEB6CE07395785CEDE17E6FEB4F36A919BD8(L_0, 0, NULL);
		U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_2 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_2), (void*)__this);
		return L_1;
	}
}
// System.Void MainScene::StopAnim()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_StopAnim_m786F7A2F00F120D025F160C8A25619552CD24CB5 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// ani_tx.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___ani_tx_8;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void MainScene::StopPopResult()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_StopPopResult_m6CAB122B383403870B6A6C5DC5CCEABBCADE95AF (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// PopResult.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___PopResult_5;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)0, NULL);
		// }
		return;
	}
}
// System.Single MainScene::GetTargetRotationForItem(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float MainScene_GetTargetRotationForItem_mEE80656AA86571D55C36D0AB058994322A6E9D5E (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, int32_t ___0_itemNumber, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_itemNumber;
		switch (((int32_t)il2cpp_codegen_subtract(L_0, 1)))
		{
			case 0:
			{
				goto IL_0022;
			}
			case 1:
			{
				goto IL_0028;
			}
			case 2:
			{
				goto IL_002e;
			}
			case 3:
			{
				goto IL_0034;
			}
			case 4:
			{
				goto IL_003a;
			}
			case 5:
			{
				goto IL_0040;
			}
		}
	}
	{
		goto IL_0046;
	}

IL_0022:
	{
		// case 1: return 0f;     // 1?????
		return (0.0f);
	}

IL_0028:
	{
		// case 2: return 60f;    // 2?????
		return (60.0f);
	}

IL_002e:
	{
		// case 3: return 120f;   // 3?????
		return (120.0f);
	}

IL_0034:
	{
		// case 4: return 300f;   // 4?????
		return (300.0f);
	}

IL_003a:
	{
		// case 5: return 240f;   // 5?????
		return (240.0f);
	}

IL_0040:
	{
		// case 6: return 180f;   // 6?????
		return (180.0f);
	}

IL_0046:
	{
		// default: return 0f;
		return (0.0f);
	}
}
// System.Void MainScene::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_OnApplicationQuit_m17120D4CC301DB5457E28FE11E4E8CDFBA9E6D9E (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_OnDisable_m0CF231E0DDC090067AC88088359242ECA8D9274F (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene_OnDestroy_m7657332A25D0A2C93CD71D2F0631FDE62BD9FE54 (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void MainScene::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MainScene__ctor_mC365650467C49386D37657E9974EB6DF9356670D (MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* __this, const RuntimeMethod* method) 
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
// System.Void MainScene/<SpinAnimation>d__20::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSpinAnimationU3Ed__20__ctor_m95F3CEB6CE07395785CEDE17E6FEB4F36A919BD8 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void MainScene/<SpinAnimation>d__20::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSpinAnimationU3Ed__20_System_IDisposable_Dispose_mD93233D65DBCD396A89BED25B2E9AA7DB666E72B (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean MainScene/<SpinAnimation>d__20::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CSpinAnimationU3Ed__20_MoveNext_mF91779CF966A0BAEA6334EE753FB456713CCBDC0 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2B164EB9D02E814EE37F29993945449F113A63BA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral491173E614C40124689C06F4F6654A982066BEEF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral526BE583C58C4E8100CB4E6693A4BF128276F5EF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6D4D6B996C6E6D24F331B554B9FF55B6E0028284);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* V_1 = NULL;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 V_4;
	memset((&V_4), 0, sizeof(V_4));
	float V_5 = 0.0f;
	float V_6 = 0.0f;
	float V_7 = 0.0f;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_1 = __this->___U3CU3E4__this_2;
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
				goto IL_0120;
			}
			case 2:
			{
				goto IL_01aa;
			}
			case 3:
			{
				goto IL_0245;
			}
		}
	}
	{
		return (bool)0;
	}

IL_0026:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// isRotating = true;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_3 = V_1;
		NullCheck(L_3);
		L_3->___isRotating_10 = (bool)1;
		// float rotationDuration = 3f; // ??????
		__this->___U3CrotationDurationU3E5__2_3 = (3.0f);
		// float fastRotationDuration = 2f; // ??????
		__this->___U3CfastRotationDurationU3E5__3_4 = (2.0f);
		// int targetItem = Random.Range(1, 7); // ???????1?6
		int32_t L_4;
		L_4 = Random_Range_m6763D9767F033357F88B6637F048F4ACA4123B68(1, 7, NULL);
		__this->___U3CtargetItemU3E5__4_5 = L_4;
		// float targetRotation = GetTargetRotationForItem(targetItem);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_5 = V_1;
		int32_t L_6 = __this->___U3CtargetItemU3E5__4_5;
		NullCheck(L_5);
		float L_7;
		L_7 = MainScene_GetTargetRotationForItem_mEE80656AA86571D55C36D0AB058994322A6E9D5E(L_5, L_6, NULL);
		__this->___U3CtargetRotationU3E5__5_6 = L_7;
		// float startRotation = spinner.transform.rotation.eulerAngles.z;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_8 = V_1;
		NullCheck(L_8);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_9 = L_8->___spinner_7;
		NullCheck(L_9);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_10;
		L_10 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_9, NULL);
		NullCheck(L_10);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_11;
		L_11 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_10, NULL);
		V_4 = L_11;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_12;
		L_12 = Quaternion_get_eulerAngles_m2DB5158B5C3A71FD60FC8A6EE43D3AAA1CFED122_inline((&V_4), NULL);
		float L_13 = L_12.___z_4;
		__this->___U3CstartRotationU3E5__6_7 = L_13;
		// float targetRotationAmount = startRotation + 360f + targetRotation; // ?????????
		float L_14 = __this->___U3CstartRotationU3E5__6_7;
		float L_15 = __this->___U3CtargetRotationU3E5__5_6;
		__this->___U3CtargetRotationAmountU3E5__7_8 = ((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(L_14, (360.0f))), L_15));
		// float elapsedRotationTime = 0f;
		__this->___U3CelapsedRotationTimeU3E5__8_9 = (0.0f);
		goto IL_0127;
	}

IL_00b3:
	{
		// float rotationAmount = Time.deltaTime / rotationDuration * (targetRotationAmount - startRotation);
		float L_16;
		L_16 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		float L_17 = __this->___U3CrotationDurationU3E5__2_3;
		float L_18 = __this->___U3CtargetRotationAmountU3E5__7_8;
		float L_19 = __this->___U3CstartRotationU3E5__6_7;
		V_5 = ((float)il2cpp_codegen_multiply(((float)(L_16/L_17)), ((float)il2cpp_codegen_subtract(L_18, L_19))));
		// spinner.transform.Rotate(Vector3.forward, rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_20 = V_1;
		NullCheck(L_20);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_21 = L_20->___spinner_7;
		NullCheck(L_21);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_22;
		L_22 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_21, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23;
		L_23 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_24 = V_5;
		NullCheck(L_22);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_22, L_23, L_24, NULL);
		// spinner_bg.transform.Rotate(Vector3.forward, -rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_25 = V_1;
		NullCheck(L_25);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_26 = L_25->___spinner_bg_6;
		NullCheck(L_26);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_27;
		L_27 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_26, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_28;
		L_28 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_29 = V_5;
		NullCheck(L_27);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_27, L_28, ((-L_29)), NULL);
		// elapsedRotationTime += Time.deltaTime;
		float L_30 = __this->___U3CelapsedRotationTimeU3E5__8_9;
		float L_31;
		L_31 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		__this->___U3CelapsedRotationTimeU3E5__8_9 = ((float)il2cpp_codegen_add(L_30, L_31));
		// yield return null;
		__this->___U3CU3E2__current_1 = NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)NULL);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0120:
	{
		__this->___U3CU3E1__state_0 = (-1);
	}

IL_0127:
	{
		// while (elapsedRotationTime < rotationDuration)
		float L_32 = __this->___U3CelapsedRotationTimeU3E5__8_9;
		float L_33 = __this->___U3CrotationDurationU3E5__2_3;
		if ((((float)L_32) < ((float)L_33)))
		{
			goto IL_00b3;
		}
	}
	{
		// float elapsedFastRotationTime = 0f;
		__this->___U3CelapsedFastRotationTimeU3E5__9_10 = (0.0f);
		goto IL_01b1;
	}

IL_0145:
	{
		// float rotationAmount = Time.deltaTime / fastRotationDuration * 720f; // 2?
		float L_34;
		L_34 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		float L_35 = __this->___U3CfastRotationDurationU3E5__3_4;
		V_6 = ((float)il2cpp_codegen_multiply(((float)(L_34/L_35)), (720.0f)));
		// spinner.transform.Rotate(Vector3.forward, rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_36 = V_1;
		NullCheck(L_36);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_37 = L_36->___spinner_7;
		NullCheck(L_37);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_38;
		L_38 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_37, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_39;
		L_39 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_40 = V_6;
		NullCheck(L_38);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_38, L_39, L_40, NULL);
		// spinner_bg.transform.Rotate(Vector3.forward, -rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_41 = V_1;
		NullCheck(L_41);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_42 = L_41->___spinner_bg_6;
		NullCheck(L_42);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_43;
		L_43 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_42, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_44;
		L_44 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_45 = V_6;
		NullCheck(L_43);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_43, L_44, ((-L_45)), NULL);
		// elapsedFastRotationTime += Time.deltaTime;
		float L_46 = __this->___U3CelapsedFastRotationTimeU3E5__9_10;
		float L_47;
		L_47 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		__this->___U3CelapsedFastRotationTimeU3E5__9_10 = ((float)il2cpp_codegen_add(L_46, L_47));
		// yield return null;
		__this->___U3CU3E2__current_1 = NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)NULL);
		__this->___U3CU3E1__state_0 = 2;
		return (bool)1;
	}

IL_01aa:
	{
		__this->___U3CU3E1__state_0 = (-1);
	}

IL_01b1:
	{
		// while (elapsedFastRotationTime < fastRotationDuration)
		float L_48 = __this->___U3CelapsedFastRotationTimeU3E5__9_10;
		float L_49 = __this->___U3CfastRotationDurationU3E5__3_4;
		if ((((float)L_48) < ((float)L_49)))
		{
			goto IL_0145;
		}
	}
	{
		// float currentRotation = spinner.transform.rotation.eulerAngles.z;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_50 = V_1;
		NullCheck(L_50);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_51 = L_50->___spinner_7;
		NullCheck(L_51);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_52;
		L_52 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_51, NULL);
		NullCheck(L_52);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_53;
		L_53 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_52, NULL);
		V_4 = L_53;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_54;
		L_54 = Quaternion_get_eulerAngles_m2DB5158B5C3A71FD60FC8A6EE43D3AAA1CFED122_inline((&V_4), NULL);
		float L_55 = L_54.___z_4;
		V_2 = L_55;
		// float remainder = currentRotation % targetRotation;
		float L_56 = V_2;
		float L_57 = __this->___U3CtargetRotationU3E5__5_6;
		V_3 = (fmodf(L_56, L_57));
		// float finalRotation = currentRotation - remainder + targetRotation;
		float L_58 = V_2;
		float L_59 = V_3;
		float L_60 = __this->___U3CtargetRotationU3E5__5_6;
		__this->___U3CfinalRotationU3E5__10_11 = ((float)il2cpp_codegen_add(((float)il2cpp_codegen_subtract(L_58, L_59)), L_60));
		goto IL_024c;
	}

IL_01f9:
	{
		// float rotationAmount = Time.deltaTime * 180f; // ?180????????
		float L_61;
		L_61 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		V_7 = ((float)il2cpp_codegen_multiply(L_61, (180.0f)));
		// spinner.transform.Rotate(Vector3.forward, rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_62 = V_1;
		NullCheck(L_62);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_63 = L_62->___spinner_7;
		NullCheck(L_63);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_64;
		L_64 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_63, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_65;
		L_65 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_66 = V_7;
		NullCheck(L_64);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_64, L_65, L_66, NULL);
		// spinner_bg.transform.Rotate(Vector3.forward, -rotationAmount);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_67 = V_1;
		NullCheck(L_67);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_68 = L_67->___spinner_bg_6;
		NullCheck(L_68);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_69;
		L_69 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_68, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_70;
		L_70 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_71 = V_7;
		NullCheck(L_69);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_69, L_70, ((-L_71)), NULL);
		// yield return null;
		__this->___U3CU3E2__current_1 = NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)NULL);
		__this->___U3CU3E1__state_0 = 3;
		return (bool)1;
	}

IL_0245:
	{
		__this->___U3CU3E1__state_0 = (-1);
	}

IL_024c:
	{
		// while (spinner.transform.rotation.eulerAngles.z < finalRotation)
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_72 = V_1;
		NullCheck(L_72);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_73 = L_72->___spinner_7;
		NullCheck(L_73);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_74;
		L_74 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_73, NULL);
		NullCheck(L_74);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_75;
		L_75 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_74, NULL);
		V_4 = L_75;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_76;
		L_76 = Quaternion_get_eulerAngles_m2DB5158B5C3A71FD60FC8A6EE43D3AAA1CFED122_inline((&V_4), NULL);
		float L_77 = L_76.___z_4;
		float L_78 = __this->___U3CfinalRotationU3E5__10_11;
		if ((((float)L_77) < ((float)L_78)))
		{
			goto IL_01f9;
		}
	}
	{
		// spinner.transform.rotation = Quaternion.Euler(0f, 0f, finalRotation);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_79 = V_1;
		NullCheck(L_79);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_80 = L_79->___spinner_7;
		NullCheck(L_80);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_81;
		L_81 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_80, NULL);
		float L_82 = __this->___U3CfinalRotationU3E5__10_11;
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_83;
		L_83 = Quaternion_Euler_m9262AB29E3E9CE94EF71051F38A28E82AEC73F90_inline((0.0f), (0.0f), L_82, NULL);
		NullCheck(L_81);
		Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D(L_81, L_83, NULL);
		// spinner_bg.transform.rotation = Quaternion.Euler(0f, 0f, -finalRotation);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_84 = V_1;
		NullCheck(L_84);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_85 = L_84->___spinner_bg_6;
		NullCheck(L_85);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_86;
		L_86 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_85, NULL);
		float L_87 = __this->___U3CfinalRotationU3E5__10_11;
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_88;
		L_88 = Quaternion_Euler_m9262AB29E3E9CE94EF71051F38A28E82AEC73F90_inline((0.0f), (0.0f), ((-L_87)), NULL);
		NullCheck(L_86);
		Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D(L_86, L_88, NULL);
		// isRotating = false;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_89 = V_1;
		NullCheck(L_89);
		L_89->___isRotating_10 = (bool)0;
		// ani_tx.SetActive(true);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_90 = V_1;
		NullCheck(L_90);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_91 = L_90->___ani_tx_8;
		NullCheck(L_91);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_91, (bool)1, NULL);
		// Invoke("StopAnim", 3);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_92 = V_1;
		NullCheck(L_92);
		MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB(L_92, _stringLiteral526BE583C58C4E8100CB4E6693A4BF128276F5EF, (3.0f), NULL);
		// score += targetItem;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_93 = V_1;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_94 = V_1;
		NullCheck(L_94);
		int32_t L_95 = L_94->___score_11;
		int32_t L_96 = __this->___U3CtargetItemU3E5__4_5;
		NullCheck(L_93);
		L_93->___score_11 = ((int32_t)il2cpp_codegen_add(L_95, L_96));
		// Debug.Log("??????" + targetItem);
		int32_t* L_97 = (&__this->___U3CtargetItemU3E5__4_5);
		String_t* L_98;
		L_98 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_97, NULL);
		String_t* L_99;
		L_99 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral2B164EB9D02E814EE37F29993945449F113A63BA, L_98, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_99, NULL);
		// text_score.text= "Marke:" + score;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_100 = V_1;
		NullCheck(L_100);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_101 = L_100->___text_score_9;
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_102 = V_1;
		NullCheck(L_102);
		int32_t* L_103 = (&L_102->___score_11);
		String_t* L_104;
		L_104 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_103, NULL);
		String_t* L_105;
		L_105 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral6D4D6B996C6E6D24F331B554B9FF55B6E0028284, L_104, NULL);
		NullCheck(L_101);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_101, L_105);
		// PopResult.SetActive(true);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_106 = V_1;
		NullCheck(L_106);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_107 = L_106->___PopResult_5;
		NullCheck(L_107);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_107, (bool)1, NULL);
		// Invoke("StopPopResult", 3);
		MainScene_tF2B107300040A766BD3321D2ACE53F958A793B5B* L_108 = V_1;
		NullCheck(L_108);
		MonoBehaviour_Invoke_mF724350C59362B0F1BFE26383209A274A29A63FB(L_108, _stringLiteral491173E614C40124689C06F4F6654A982066BEEF, (3.0f), NULL);
		// }
		return (bool)0;
	}
}
// System.Object MainScene/<SpinAnimation>d__20::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSpinAnimationU3Ed__20_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m2ABF52570610973C4CF2D116BC1E3C973A9796D8 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void MainScene/<SpinAnimation>d__20::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSpinAnimationU3Ed__20_System_Collections_IEnumerator_Reset_mDCC27E477B437217E43F1E086C34B153D2EAE783 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CSpinAnimationU3Ed__20_System_Collections_IEnumerator_Reset_mDCC27E477B437217E43F1E086C34B153D2EAE783_RuntimeMethod_var)));
	}
}
// System.Object MainScene/<SpinAnimation>d__20::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSpinAnimationU3Ed__20_System_Collections_IEnumerator_get_Current_m357FA5D819F698C2D7AADEA4636407F914E584F1 (U3CSpinAnimationU3Ed__20_tBD5BAE06852C669D254455BD52FD6F39FAAF36CA* __this, const RuntimeMethod* method) 
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
// System.Void ProgressBar::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProgressBar_Start_m688CEB482097275163F3E0DA21428FBC0FB8F8F5 (ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* __this, const RuntimeMethod* method) 
{
	{
		// SetProgress(0f); // ?????0
		ProgressBar_SetProgress_mB0CA374307C310BD4E66B22D6FC5AD2CDE6D3916(__this, (0.0f), NULL);
		// }
		return;
	}
}
// System.Void ProgressBar::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProgressBar_Update_m04A17A4B9D006FD9DB6141847BF0E3E1A52ECFAD (ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* __this, const RuntimeMethod* method) 
{
	{
		// if (slider.value < targetProgress)
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_0 = __this->___slider_4;
		NullCheck(L_0);
		float L_1;
		L_1 = VirtualFuncInvoker0< float >::Invoke(46 /* System.Single UnityEngine.UI.Slider::get_value() */, L_0);
		float L_2 = __this->___targetProgress_6;
		if ((!(((float)L_1) < ((float)L_2))))
		{
			goto IL_0032;
		}
	}
	{
		// slider.value += fillSpeed * Time.deltaTime;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_3 = __this->___slider_4;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_4 = L_3;
		NullCheck(L_4);
		float L_5;
		L_5 = VirtualFuncInvoker0< float >::Invoke(46 /* System.Single UnityEngine.UI.Slider::get_value() */, L_4);
		float L_6 = __this->___fillSpeed_5;
		float L_7;
		L_7 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		NullCheck(L_4);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_4, ((float)il2cpp_codegen_add(L_5, ((float)il2cpp_codegen_multiply(L_6, L_7)))));
		return;
	}

IL_0032:
	{
		// else if (slider.value > targetProgress)
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_8 = __this->___slider_4;
		NullCheck(L_8);
		float L_9;
		L_9 = VirtualFuncInvoker0< float >::Invoke(46 /* System.Single UnityEngine.UI.Slider::get_value() */, L_8);
		float L_10 = __this->___targetProgress_6;
		if ((!(((float)L_9) > ((float)L_10))))
		{
			goto IL_0056;
		}
	}
	{
		// slider.value = targetProgress;
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_11 = __this->___slider_4;
		float L_12 = __this->___targetProgress_6;
		NullCheck(L_11);
		VirtualActionInvoker1< float >::Invoke(47 /* System.Void UnityEngine.UI.Slider::set_value(System.Single) */, L_11, L_12);
	}

IL_0056:
	{
		// }
		return;
	}
}
// System.Void ProgressBar::SetProgress(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProgressBar_SetProgress_mB0CA374307C310BD4E66B22D6FC5AD2CDE6D3916 (ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* __this, float ___0_progress, const RuntimeMethod* method) 
{
	{
		// targetProgress = Mathf.Clamp01(progress);
		float L_0 = ___0_progress;
		float L_1;
		L_1 = Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline(L_0, NULL);
		__this->___targetProgress_6 = L_1;
		// }
		return;
	}
}
// System.Void ProgressBar::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProgressBar__ctor_mF6AF0DB3866AC00A9C3A84543C332986CC3B9690 (ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* __this, const RuntimeMethod* method) 
{
	{
		// public float fillSpeed = 0.5f; // ???????
		__this->___fillSpeed_5 = (0.5f);
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
// System.Void SpinnerController::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinnerController_Update_m398EF5DF0DC0C771F4F66F594906E1D4684335AB (SpinnerController_tFFE28A65514003EFD815E8D82BF0F540878317C8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	{
		// float horizontalInput = Input.GetAxis("Horizontal");
		float L_0;
		L_0 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E, NULL);
		V_0 = L_0;
		// transform.Rotate(Vector3.up, rotationSpeed * horizontalInput * Time.deltaTime);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_1;
		L_1 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2;
		L_2 = Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline(NULL);
		float L_3 = __this->___rotationSpeed_4;
		float L_4 = V_0;
		float L_5;
		L_5 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		NullCheck(L_1);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_1, L_2, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_multiply(L_3, L_4)), L_5)), NULL);
		// }
		return;
	}
}
// System.Void SpinnerController::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinnerController__ctor_m793E67E50F53A98C0C51876B75E26D971BA20842 (SpinnerController_tFFE28A65514003EFD815E8D82BF0F540878317C8* __this, const RuntimeMethod* method) 
{
	{
		// public float rotationSpeed = 5f;
		__this->___rotationSpeed_4 = (5.0f);
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
// System.Void StartScene::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_Awake_mC8378386ECC88EDE895D24B406C31EB031E66BAF (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// InintView();
		StartScene_InintView_mDDA3FF2352E18DD3F1EF769BE0B4F419367F5C1E(__this, NULL);
		// }
		return;
	}
}
// System.Void StartScene::InintView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_InintView_mDDA3FF2352E18DD3F1EF769BE0B4F419367F5C1E (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_OnEnable_m930AF32FECAC7B408A941C40C0C13A0C95E568C9 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// UpdateView();
		StartScene_UpdateView_mD20779A871A4094C7E2FEDBBE3CF3543E03A4873(__this, NULL);
		// }
		return;
	}
}
// System.Void StartScene::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_Reset_mE3EF2E7554E1AFD713F82148239B0BAE6105FF19 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_Start_m44C6CC4A38BCFAC1521008BF287A26EDA8E69FD1 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// PopStart.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___PopStart_4;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)1, NULL);
		// }
		return;
	}
}
// System.Void StartScene::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_Update_m6B0BE38664337FFB43C3ABCC26B293AA7D6D7A0C (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::UpdateView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_UpdateView_mD20779A871A4094C7E2FEDBBE3CF3543E03A4873 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::OnStartClick()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_OnStartClick_mA20ED273323FF4922AEA09547E84A2E2307F80EB (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC815B3C4337048311EC4F9295DCA65F216869AD2);
		s_Il2CppMethodInitialized = true;
	}
	{
		// PopLoad.SetActive(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___PopLoad_5;
		NullCheck(L_0);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_0, (bool)1, NULL);
		// PopStart.SetActive(false);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = __this->___PopStart_4;
		NullCheck(L_1);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_1, (bool)0, NULL);
		// InvokeRepeating("UpdateProgressBar", 2.0f, updateInterval);
		float L_2 = __this->___updateInterval_7;
		MonoBehaviour_InvokeRepeating_mF208501E0E4918F9168BBBA5FC50D8F80D01514D(__this, _stringLiteralC815B3C4337048311EC4F9295DCA65F216869AD2, (2.0f), L_2, NULL);
		// }
		return;
	}
}
// System.Void StartScene::UpdateProgressBar()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_UpdateProgressBar_m212E37EDE9763EFFDBDCE05B1FC989002331573B (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC815B3C4337048311EC4F9295DCA65F216869AD2);
		s_Il2CppMethodInitialized = true;
	}
	{
		// progressBar.SetProgress(progressBar.slider.value + 0.3f);
		ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* L_0 = __this->___progressBar_6;
		ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* L_1 = __this->___progressBar_6;
		NullCheck(L_1);
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_2 = L_1->___slider_4;
		NullCheck(L_2);
		float L_3;
		L_3 = VirtualFuncInvoker0< float >::Invoke(46 /* System.Single UnityEngine.UI.Slider::get_value() */, L_2);
		NullCheck(L_0);
		ProgressBar_SetProgress_mB0CA374307C310BD4E66B22D6FC5AD2CDE6D3916(L_0, ((float)il2cpp_codegen_add(L_3, (0.300000012f))), NULL);
		// if (progressBar.slider.value >= 1.0f)
		ProgressBar_t2F62F200309FC31DDC2F9C89BDCF65323D4A4E61* L_4 = __this->___progressBar_6;
		NullCheck(L_4);
		Slider_t87EA570E3D6556CABF57456C2F3873FFD86E652F* L_5 = L_4->___slider_4;
		NullCheck(L_5);
		float L_6;
		L_6 = VirtualFuncInvoker0< float >::Invoke(46 /* System.Single UnityEngine.UI.Slider::get_value() */, L_5);
		if ((!(((float)L_6) >= ((float)(1.0f)))))
		{
			goto IL_0049;
		}
	}
	{
		// CancelInvoke("UpdateProgressBar"); // ???????
		MonoBehaviour_CancelInvoke_m268FFD58AFF64C07FD4C9B9B8B85F58BD86F3A01(__this, _stringLiteralC815B3C4337048311EC4F9295DCA65F216869AD2, NULL);
		// ShowMainScreen();
		StartScene_ShowMainScreen_m1AB56068EDDC6C2B9FDD8A1A85F303192DB922D8(__this, NULL);
	}

IL_0049:
	{
		// }
		return;
	}
}
// System.Void StartScene::ShowMainScreen()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_ShowMainScreen_m1AB56068EDDC6C2B9FDD8A1A85F303192DB922D8 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral884820433266E121D9AF505AF4DE98B3BA081DC8);
		s_Il2CppMethodInitialized = true;
	}
	{
		// SceneManager.LoadScene("MainScene");
		il2cpp_codegen_runtime_class_init_inline(SceneManager_tA0EF56A88ACA4A15731AF7FDC10A869FA4C698FA_il2cpp_TypeInfo_var);
		SceneManager_LoadScene_mBB3DBC1601A21F8F4E8A5D68FED30EA9412F218E(_stringLiteral884820433266E121D9AF505AF4DE98B3BA081DC8, NULL);
		// }
		return;
	}
}
// System.Void StartScene::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_OnApplicationQuit_m17ED19B5C6716CBC64D924236305870D15935A0F (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_OnDisable_m7BA0F3BA50059CA6B2254D2C79D310A9F1536FF3 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene_OnDestroy_m2409E4B8F21ADD2DFBB7E619E0B62C4309C2F312 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void StartScene::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartScene__ctor_m05CF7AAF841A8D2B7F817BA0283DC91F643EF489 (StartScene_t82F5873EB56A8C552D34C2506E8BE32B68D61670* __this, const RuntimeMethod* method) 
{
	{
		// public float updateInterval = 1.0f; // ??????
		__this->___updateInterval_7 = (1.0f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* EventSystem_get_currentSelectedGameObject_mD606FFACF3E72755298A523CBB709535CF08C98A_inline (EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* __this, const RuntimeMethod* method) 
{
	{
		// get { return m_CurrentSelected; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___m_CurrentSelected_10;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Quaternion_get_eulerAngles_m2DB5158B5C3A71FD60FC8A6EE43D3AAA1CFED122_inline (Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974* __this, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_0 = (*(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974*)__this);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Quaternion_Internal_ToEulerRad_m5BD0EEC543120C320DC77FCCDFD2CE2E6BD3F1A8(L_0, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2;
		L_2 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_1, (57.2957802f), NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3;
		L_3 = Quaternion_Internal_MakePositive_m73E2D01920CB0DFE661A55022C129E8617F0C9A8(L_2, NULL);
		V_0 = L_3;
		goto IL_001e;
	}

IL_001e:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___forwardVector_11;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Quaternion_Euler_m9262AB29E3E9CE94EF71051F38A28E82AEC73F90_inline (float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) 
{
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		float L_0 = ___0_x;
		float L_1 = ___1_y;
		float L_2 = ___2_z;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3;
		memset((&L_3), 0, sizeof(L_3));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_3), L_0, L_1, L_2, /*hidden argument*/NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		L_4 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_3, (0.0174532924f), NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_5;
		L_5 = Quaternion_Internal_FromEulerRad_m66D4475341F53949471E6870FB5C5E4A5E9BA93E(L_4, NULL);
		V_0 = L_5;
		goto IL_001b;
	}

IL_001b:
	{
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6 = V_0;
		return L_6;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline (float ___0_value, const RuntimeMethod* method) 
{
	bool V_0 = false;
	float V_1 = 0.0f;
	bool V_2 = false;
	{
		float L_0 = ___0_value;
		V_0 = (bool)((((float)L_0) < ((float)(0.0f)))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		V_1 = (0.0f);
		goto IL_002d;
	}

IL_0015:
	{
		float L_2 = ___0_value;
		V_2 = (bool)((((float)L_2) > ((float)(1.0f)))? 1 : 0);
		bool L_3 = V_2;
		if (!L_3)
		{
			goto IL_0029;
		}
	}
	{
		V_1 = (1.0f);
		goto IL_002d;
	}

IL_0029:
	{
		float L_4 = ___0_value;
		V_1 = L_4;
		goto IL_002d;
	}

IL_002d:
	{
		float L_5 = V_1;
		return L_5;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___upVector_7;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		float L_2 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3 = ___0_a;
		float L_4 = L_3.___y_3;
		float L_5 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_a;
		float L_7 = L_6.___z_4;
		float L_8 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		memset((&L_9), 0, sizeof(L_9));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_9), ((float)il2cpp_codegen_multiply(L_1, L_2)), ((float)il2cpp_codegen_multiply(L_4, L_5)), ((float)il2cpp_codegen_multiply(L_7, L_8)), /*hidden argument*/NULL);
		V_0 = L_9;
		goto IL_0021;
	}

IL_0021:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = V_0;
		return L_10;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_x;
		__this->___x_2 = L_0;
		float L_1 = ___1_y;
		__this->___y_3 = L_1;
		float L_2 = ___2_z;
		__this->___z_4 = L_2;
		return;
	}
}
