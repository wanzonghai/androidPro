package com.kdfefhg.oefejgg;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Member;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class pluginsBaseReflector {

    //////////////////////////////////////////////////
    protected Class<?> mType;
    protected Object mCaller;
    protected Constructor mConstructor;
    protected Field mField;
    protected Method mMethod;

    public static class efygsydg extends Exception {

        public efygsydg(String message) {
            super(message);
        }
        public efygsydg(String message, Throwable cause) {
            super(message, cause);
        }

    }


    public static pluginsBaseReflector on(@NonNull Class<?> type) {
        pluginsBaseReflector reflector = new pluginsBaseReflector();
        reflector.mType = type;
        new koefig.oxqu.ibvk.ruuv.Pcgbxntnj();
        return reflector;
    }

    public static pluginsBaseReflector with(@NonNull Object caller) throws efygsydg {
        return on(caller.getClass()).bind(caller);
    }

    public pluginsBaseReflector constructor(@Nullable Class<?>... parameterTypes) throws efygsydg {
        new koefig.oxqu.ibvk.ruuv.Bmdtgasnvr();
        try {
            mConstructor = mType.getDeclaredConstructor(parameterTypes);
            mConstructor.setAccessible(true);
            mField = null;
            mMethod = null;
            return this;
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    public static pluginsBaseReflector on(@NonNull String name) throws efygsydg {
        return on(name, true, pluginsBaseReflector.class.getClassLoader());
    }

    protected pluginsBaseReflector() {

    }
    public static pluginsBaseReflector on(@NonNull String name, boolean initialize) throws efygsydg {
        return on(name, initialize, pluginsBaseReflector.class.getClassLoader());
    }
    public static pluginsBaseReflector on(@NonNull String name, boolean initialize, @Nullable ClassLoader loader) throws efygsydg {
        try {
            return on(Class.forName(name, initialize, loader));
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    @SuppressWarnings("unchecked")
    public <R> R newInstance(@Nullable Object ... initargs) throws efygsydg {
        if (mConstructor == null) {
            throw new efygsydg("Constructor was null!");
        }
        try {
            return (R) mConstructor.newInstance(initargs);
        } catch (InvocationTargetException e) {
            throw new efygsydg("Oops!", e.getTargetException());
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    public pluginsBaseReflector bind(@Nullable Object caller) throws efygsydg {
        mCaller = checked(caller);
        new koefig.vpb.vzp.Jyqppy();
        return this;
    }

    public pluginsBaseReflector unbind() {
        mCaller = null;
        return this;
    }

    protected Field findField(@NonNull String name) throws NoSuchFieldException {
        try {
            return mType.getField(name);
        } catch (NoSuchFieldException e) {
            for (Class<?> cls = mType; cls != null; cls = cls.getSuperclass()) {
                try {
                    return cls.getDeclaredField(name);
                } catch (NoSuchFieldException ex) {
                    // Ignored
                }
            }
            throw e;
        }
    }

    public pluginsBaseReflector field(@NonNull String name) throws efygsydg {
        try {
            mField = findField(name);
            mField.setAccessible(true);
            mConstructor = null;
            mMethod = null;
            return this;
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    protected Object checked(@Nullable Object caller) throws efygsydg {
        if (caller == null || mType.isInstance(caller)) {
            return caller;
        }
        throw new efygsydg("Caller [" + caller + "] is not a instance of type [" + mType + "]!");
    }

    protected void check(@Nullable Object caller, @Nullable Member member, @NonNull String name) throws efygsydg {
        if (member == null) {
            throw new efygsydg(name + " was null!");
        }
        if (caller == null && !Modifier.isStatic(member.getModifiers())) {
            throw new efygsydg("Need a caller!");
        }
        checked(caller);
    }

    @SuppressWarnings("unchecked")
    public <R> R get() throws efygsydg {
        return get(mCaller);
    }

    @SuppressWarnings("unchecked")
    public <R> R get(@Nullable Object caller) throws efygsydg {
        check(caller, mField, "Field");
        try {
            return (R) mField.get(caller);
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    public pluginsBaseReflector set(@Nullable Object value) throws efygsydg {
        return set(mCaller, value);
    }

    public pluginsBaseReflector set(@Nullable Object caller, @Nullable Object value) throws efygsydg {
        check(caller, mField, "Field");
        new koefig.ddknh.frtgf.Ldrsiz();
        try {
            mField.set(caller, value);
            return this;
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    protected Method findMethod(@NonNull String name, @Nullable Class<?>... parameterTypes) throws NoSuchMethodException {
        try {
            return mType.getMethod(name, parameterTypes);
        } catch (NoSuchMethodException e) {
            for (Class<?> cls = mType; cls != null; cls = cls.getSuperclass()) {
                try {
                    return cls.getDeclaredMethod(name, parameterTypes);
                } catch (NoSuchMethodException ex) {
                    // Ignored
                }
            }
            throw e;
        }
    }

    public pluginsBaseReflector method(@NonNull String name, @Nullable Class<?>... parameterTypes) throws efygsydg {
        try {
            mMethod = findMethod(name, parameterTypes);
            mMethod.setAccessible(true);
            mConstructor = null;
            mField = null;
            return this;
        } catch (NoSuchMethodException e) {
            throw new efygsydg("Oops!", e);
        }
    }



    public <R> R call(@Nullable Object... args) throws efygsydg {
        return callByCaller(mCaller, args);
    }

    @SuppressWarnings("unchecked")
    public <R> R callByCaller(@Nullable Object caller, @Nullable Object... args) throws efygsydg {
        check(caller, mMethod, "Method");
        try {
            return (R) mMethod.invoke(caller, args);
        } catch (InvocationTargetException e) {
            throw new efygsydg("Oops!", e.getTargetException());
        } catch (Throwable e) {
            throw new efygsydg("Oops!", e);
        }
    }

    public static class Cysxhdazkfolqv extends pluginsBaseReflector {

        protected Throwable mIgnored;

        public static Cysxhdazkfolqv on(@Nullable Class<?> type) {
            return on(type, (type == null) ? new efygsydg("Type was null!") : null);
        }

        private static Cysxhdazkfolqv on(@Nullable Class<?> type, @Nullable Throwable ignored) {
            Cysxhdazkfolqv reflector = new Cysxhdazkfolqv();
            reflector.mType = type;
            reflector.mIgnored = ignored;
            return reflector;
        }

        public static Cysxhdazkfolqv with(@Nullable Object caller) {
            if (caller == null) {
                return on((Class<?>) null);
            }
            return on(caller.getClass()).bind(caller);
        }

        public static Cysxhdazkfolqv on(@NonNull String name) {
            return on(name, true, Cysxhdazkfolqv.class.getClassLoader());
        }





        public static Cysxhdazkfolqv on(@NonNull String name, boolean initialize) {
            return on(name, initialize, Cysxhdazkfolqv.class.getClassLoader());
        }

        public static Cysxhdazkfolqv on(@NonNull String name, boolean initialize, @Nullable ClassLoader loader) {
            Class<?> cls = null;
            try {
                cls = Class.forName(name, initialize, loader);
                return on(cls, null);
            } catch (Throwable e) {
                // Log.w(LOG_TAG, "Oops!", e);
                return on(cls, e);
            }
        }

        protected Cysxhdazkfolqv() {

        }

        public Throwable getIgnored() {
            return mIgnored;
        }

        protected boolean skip() {
            return skipAlways() || mIgnored != null;
        }

        protected boolean skipAlways() {
            return mType == null;
        }

        @Override
        public Cysxhdazkfolqv constructor(@Nullable Class<?>... parameterTypes) {
            if (skipAlways()) {
                return this;
            }
            try {
                mIgnored = null;
                super.constructor(parameterTypes);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return this;
        }

        @Override
        public <R> R newInstance(@Nullable Object... initargs) {
            if (skip()) {
                return null;
            }
            try {
                mIgnored = null;
                return super.newInstance(initargs);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return null;
        }

        @Override
        public Cysxhdazkfolqv bind(@Nullable Object obj) {
            if (skipAlways()) {
                return this;
            }
            try {
                mIgnored = null;
                super.bind(obj);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return this;
        }

        @Override
        public Cysxhdazkfolqv unbind() {
            super.unbind();
            return this;
        }

        @Override
        public Cysxhdazkfolqv field(@NonNull String name) {
            if (skipAlways()) {
                return this;
            }
            try {
                mIgnored = null;
                super.field(name);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return this;
        }

        @Override
        public <R> R get() {
            if (skip()) {
                return null;
            }
            try {
                mIgnored = null;
                return super.get();
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return null;
        }

        @Override
        public <R> R get(@Nullable Object caller) {
            if (skip()) {
                return null;
            }
            try {
                mIgnored = null;
                return super.get(caller);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return null;
        }

        @Override
        public Cysxhdazkfolqv set(@Nullable Object value) {
            if (skip()) {
                return this;
            }
            try {
                mIgnored = null;
                super.set(value);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return this;
        }

        @Override
        public Cysxhdazkfolqv set(@Nullable Object caller, @Nullable Object value) {
            if (skip()) {
                return this;
            }
            try {
                mIgnored = null;
                super.set(caller, value);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return this;
        }

        @Override
        public Cysxhdazkfolqv method(@NonNull String name, @Nullable Class<?>... parameterTypes) {
            if (skipAlways()) {
                return this;
            }
            try {
                mIgnored = null;
                super.method(name, parameterTypes);
            } catch (Throwable e) {
                mIgnored = e;
            }
            return this;
        }

        @Override
        public <R> R call(@Nullable Object... args)  {
            if (skip()) {
                return null;
            }
            try {
                mIgnored = null;
                return super.call(args);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return null;
        }

        @Override
        public <R> R callByCaller(@Nullable Object caller, @Nullable Object... args) {
            if (skip()) {
                return null;
            }
            try {
                mIgnored = null;
                return super.callByCaller(caller, args);
            } catch (Throwable e) {
                mIgnored = e;
                // Log.w(LOG_TAG, "Oops!", e);
            }
            return null;
        }
    }
}