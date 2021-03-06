/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class SoundToAnimation : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal SoundToAnimation(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(SoundToAnimation obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~SoundToAnimation() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          testPINVOKE.delete_SoundToAnimation(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public SoundToAnimation(string Anim, string Sound) : this(testPINVOKE.new_SoundToAnimation(Anim, Sound), true) {
  }

  public string Animation {
    set {
      testPINVOKE.SoundToAnimation_Animation_set(swigCPtr, value);
    } 
    get {
      string ret = testPINVOKE.SoundToAnimation_Animation_get(swigCPtr);
      return ret;
    } 
  }

  public string AnimSound {
    set {
      testPINVOKE.SoundToAnimation_AnimSound_set(swigCPtr, value);
    } 
    get {
      string ret = testPINVOKE.SoundToAnimation_AnimSound_get(swigCPtr);
      return ret;
    } 
  }

}
