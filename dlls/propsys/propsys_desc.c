/*
 * IPropertyDescription implementation
 *
 * Copyright 2024 Vibhav Pant
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define COBJMACROS

#include <propsys.h>
#include <propkey.h>

#include <wine/debug.h>

#include "propsys_private.h"

WINE_DEFAULT_DEBUG_CHANNEL( propsys );

struct property_description
{
    IPropertyDescription IPropertyDescription_iface;

    PROPERTYKEY key;
    VARTYPE type;
    PROPDESC_TYPE_FLAGS type_flags;

    LONG ref;
    WCHAR canonical_name[1];
};

static inline struct property_description *
impl_from_IPropertyDescription( IPropertyDescription *iface )
{
    return CONTAINING_RECORD( iface, struct property_description, IPropertyDescription_iface );
}

static HRESULT WINAPI propdesc_QueryInterface( IPropertyDescription *iface, REFIID iid, void **out )
{
    TRACE( "(%p, %s, %p)\n", iface, debugstr_guid( iid ), out );
    *out = NULL;

    if (IsEqualGUID( &IID_IUnknown, iid ) ||
        IsEqualGUID( &IID_IPropertyDescription, iid ))
    {
        *out = iface;
        IUnknown_AddRef( iface );
        return S_OK;
    }

    FIXME( "%s not implemented\n", debugstr_guid( iid ) );
    return E_NOINTERFACE;
}

static ULONG WINAPI propdesc_AddRef( IPropertyDescription *iface )
{
    struct property_description *impl;
    TRACE( "(%p)\n", iface );
    impl = impl_from_IPropertyDescription( iface );
    return InterlockedIncrement( &impl->ref );
}

static ULONG WINAPI propdesc_Release( IPropertyDescription *iface )
{
    struct property_description *impl;
    ULONG ref;

    TRACE( "(%p)\n", iface );

    impl = impl_from_IPropertyDescription( iface );
    ref = InterlockedDecrement( &impl->ref );
    if (!ref)
        free( impl );

    return ref;
}

static HRESULT WINAPI propdesc_GetPropertyKey( IPropertyDescription *iface, PROPERTYKEY *pkey )
{
    struct property_description *impl;

    TRACE( "(%p, %p)\n", iface, pkey );
    impl = impl_from_IPropertyDescription( iface );
    *pkey = impl->key;
    return S_OK;
}

static HRESULT WINAPI propdesc_GetCanonicalName( IPropertyDescription *iface, LPWSTR *name )
{
    struct property_description *impl;

    TRACE( "(%p, %p)\n", iface, name );
    impl = impl_from_IPropertyDescription( iface );
    *name = CoTaskMemAlloc( wcslen( impl->canonical_name ) * sizeof( WCHAR ) );
    if (!*name)
        return E_OUTOFMEMORY;
    wcscpy( *name, impl->canonical_name );
    return S_OK;
}

static HRESULT WINAPI propdesc_GetPropertyType( IPropertyDescription *iface, VARTYPE *vt )
{
    struct property_description *impl;

    TRACE( "(%p, %p)\n", iface, vt );
    impl = impl_from_IPropertyDescription( iface );
    *vt = impl->type;
    return S_OK;
}

static HRESULT WINAPI propdesc_GetDisplayName( IPropertyDescription *iface, LPWSTR *name )
{
    FIXME( "(%p, %p) semi-stub!\n", iface, name );
    return IPropertyDescription_GetCanonicalName( iface, name );
}

static HRESULT WINAPI propdesc_GetEditInvitation( IPropertyDescription *iface, LPWSTR *invite )
{
    FIXME( "(%p, %p) stub!\n", iface, invite );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetTypeFlags( IPropertyDescription *iface, PROPDESC_TYPE_FLAGS mask,
                                             PROPDESC_TYPE_FLAGS *flags )
{
    struct property_description *impl;

    TRACE( "(%p, %#x, %p)\n", iface, mask, flags );
    impl = impl_from_IPropertyDescription( iface );
    *flags = mask & impl->type_flags;
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetViewFlags( IPropertyDescription *iface, PROPDESC_VIEW_FLAGS *flags )
{
    FIXME( "(%p, %p) stub!\n", iface, flags );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetDefaultColumnWidth( IPropertyDescription *iface, UINT *chars )
{
    FIXME( "(%p, %p) stub!\n", iface, chars );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetDisplayType( IPropertyDescription *iface, PROPDESC_DISPLAYTYPE *type )
{
    FIXME( "(%p, %p) stub!\n", iface, type );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetColumnState( IPropertyDescription *iface, SHCOLSTATEF *flags )
{
    FIXME( "(%p, %p) stub!\n", iface, flags );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetGroupingRange( IPropertyDescription *iface, PROPDESC_GROUPING_RANGE *range )
{
    FIXME( "(%p, %p) stub!\n", iface, range );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetRelativeDescriptionType( IPropertyDescription *iface,
                                                           PROPDESC_RELATIVEDESCRIPTION_TYPE *type )
{
    FIXME( "(%p, %p) stub!\n", iface, type );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetRelativeDescription( IPropertyDescription *iface, REFPROPVARIANT propvar1,
                                                       REFPROPVARIANT propvar2, LPWSTR *desc1, LPWSTR *desc2 )
{
    FIXME( "(%p, %p, %p, %p, %p) stub!\n", iface, propvar1, propvar2, desc1, desc2 );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetSortDescription( IPropertyDescription *iface, PROPDESC_SORTDESCRIPTION *psd )
{
    FIXME( "(%p, %p) stub!\n", iface, psd );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetSortDescriptionLabel( IPropertyDescription *iface, BOOL descending, LPWSTR *desc )
{
    FIXME( "(%p, %d, %p) stub!\n", iface, descending, desc );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetAggregationType( IPropertyDescription *iface, PROPDESC_AGGREGATION_TYPE *type )
{
    FIXME( "(%p, %p) stub!\n", iface, type );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetConditionType( IPropertyDescription *iface, PROPDESC_CONDITION_TYPE *cond_type,
                                                 CONDITION_OPERATION *op_default )
{
    FIXME( "(%p, %p, %p) stub!\n", iface, cond_type, op_default );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_GetEnumTypeList( IPropertyDescription *iface, REFIID riid, void **out )
{
    FIXME( "(%p, %s, %p) stub!\n", iface, debugstr_guid( riid ), out );
    *out = NULL;
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_CoerceToCanonicalValue( IPropertyDescription *iface, PROPVARIANT *propvar )
{
    FIXME( "(%p, %p) stub!\n", iface, propvar );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_FormatForDisplay( IPropertyDescription *iface, REFPROPVARIANT propvar,
                                        PROPDESC_FORMAT_FLAGS flags, LPWSTR *display )
{
    FIXME( "(%p, %p, %#x, %p) stub!\n", iface, propvar, flags, display );
    return E_NOTIMPL;
}

static HRESULT WINAPI propdesc_IsValueCanonical( IPropertyDescription *iface, REFPROPVARIANT propvar )
{
    FIXME( "(%p, %p) stub!\n", iface, propvar );
    return E_NOTIMPL;
}

const static IPropertyDescriptionVtbl property_description_vtbl =
{
    /* IUnknown */
    propdesc_QueryInterface,
    propdesc_AddRef,
    propdesc_Release,
    /* IPropertyDescription */
    propdesc_GetPropertyKey,
    propdesc_GetCanonicalName,
    propdesc_GetPropertyType,
    propdesc_GetDisplayName,
    propdesc_GetEditInvitation,
    propdesc_GetTypeFlags,
    propdesc_GetViewFlags,
    propdesc_GetDefaultColumnWidth,
    propdesc_GetDisplayType,
    propdesc_GetColumnState,
    propdesc_GetGroupingRange,
    propdesc_GetRelativeDescriptionType,
    propdesc_GetRelativeDescription,
    propdesc_GetSortDescription,
    propdesc_GetSortDescriptionLabel,
    propdesc_GetAggregationType,
    propdesc_GetConditionType,
    propdesc_GetEnumTypeList,
    propdesc_CoerceToCanonicalValue,
    propdesc_FormatForDisplay,
    propdesc_IsValueCanonical
};

struct system_property_description
{
    const WCHAR *canonical_name;
    const PROPERTYKEY *key;

    VARTYPE type;
};

/* It may be ideal to construct rb_trees for looking up property descriptions by name and key if this array gets large
 * enough. */
static struct system_property_description system_properties[] =
{
    {L"System.Devices.ContainerId", &PKEY_Devices_ContainerId, VT_CLSID},
    {L"System.Devices.InterfaceClassGuid", &PKEY_Devices_InterfaceClassGuid, VT_CLSID},
    {L"System.Devices.DeviceInstanceId", &PKEY_Devices_DeviceInstanceId, VT_CLSID},
    {L"System.Devices.InterfaceEnabled", &PKEY_Devices_InterfaceEnabled, VT_BOOL},
    {L"System.Devices.ClassGuid", &PKEY_Devices_ClassGuid, VT_CLSID},
    {L"System.Devices.CompatibleIds", &PKEY_Devices_CompatibleIds, VT_VECTOR | VT_LPWSTR},
    {L"System.Devices.DeviceCapabilities", &PKEY_Devices_DeviceCapabilities, VT_UI2},
    {L"System.Devices.DeviceHasProblem", &PKEY_Devices_DeviceHasProblem, VT_BOOL},
    {L"System.Devices.DeviceManufacturer", &PKEY_Devices_DeviceManufacturer, VT_LPWSTR},
    {L"System.Devices.HardwareIds", &PKEY_Devices_HardwareIds, VT_VECTOR | VT_LPWSTR},
    {L"System.Devices.Parent", &PKEY_Devices_Parent, VT_LPWSTR},
    {L"System.ItemNameDisplay", &PKEY_ItemNameDisplay, VT_LPWSTR},
    {L"System.Devices.Category", &PKEY_Devices_Category, VT_VECTOR | VT_LPWSTR},
    {L"System.Devices.CategoryIds", &PKEY_Devices_CategoryIds, VT_VECTOR | VT_LPWSTR},
    {L"System.Devices.CategoryPlural", &PKEY_Devices_CategoryPlural, VT_VECTOR | VT_LPWSTR},
    {L"System.Devices.Connected", &PKEY_Devices_Connected, VT_BOOL},
    {L"System.Devices.GlyphIcon", &PKEY_Devices_GlyphIcon, VT_LPWSTR},
};

static HRESULT propdesc_from_system_property( const struct system_property_description *desc, IPropertyDescription **out )
{
    struct property_description *impl;

    impl = calloc(1, offsetof( struct property_description, canonical_name[wcslen(desc->canonical_name)] ));
    if (!impl)
        return E_OUTOFMEMORY;

    impl->IPropertyDescription_iface.lpVtbl = &property_description_vtbl;
    impl->key = *desc->key;
    wcscpy( impl->canonical_name, desc->canonical_name );
    impl->type = desc->type;
    impl->type_flags = PDTF_ISINNATE;
    if (impl->type & VT_VECTOR)
        impl->type_flags |= PDTF_MULTIPLEVALUES;
    impl->ref = 1;

    *out = &impl->IPropertyDescription_iface;
    return S_OK;
}

HRESULT propsys_get_system_propdesc_by_name( const WCHAR *name, IPropertyDescription **desc )
{
    SIZE_T i;

    for (i = 0; i < ARRAY_SIZE( system_properties ); i++)
    {
        if (!wcscmp( name, system_properties[i].canonical_name ))
            return propdesc_from_system_property( &system_properties[i], desc );
    }

    return TYPE_E_ELEMENTNOTFOUND;
}

HRESULT propsys_get_system_propdesc_by_key( const PROPERTYKEY *key, IPropertyDescription **desc )
{
    SIZE_T i;

    for (i = 0; i < ARRAY_SIZE( system_properties ); i++)
    {
        if (!memcmp( key, system_properties[i].key, sizeof( *key ) ))
            return propdesc_from_system_property( &system_properties[i], desc );
    }

    return TYPE_E_ELEMENTNOTFOUND;
}
