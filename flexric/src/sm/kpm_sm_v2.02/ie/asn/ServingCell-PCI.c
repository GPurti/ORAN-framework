/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm-kpmv2.02.asn1"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps -D asn`
 */

#include "ServingCell-PCI.h"

static asn_per_constraints_t asn_PER_type_ServingCell_PCI_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ServingCell_PCI_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ServingCell_PCI, choice.nR),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_PCI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nR"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ServingCell_PCI, choice.eUTRA),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E_UTRA_PCI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eUTRA"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_ServingCell_PCI_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nR */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* eUTRA */
};
static asn_CHOICE_specifics_t asn_SPC_ServingCell_PCI_specs_1 = {
	sizeof(struct ServingCell_PCI),
	offsetof(struct ServingCell_PCI, _asn_ctx),
	offsetof(struct ServingCell_PCI, present),
	sizeof(((struct ServingCell_PCI *)0)->present),
	asn_MAP_ServingCell_PCI_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ServingCell_PCI = {
	"ServingCell-PCI",
	"ServingCell-PCI",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_ServingCell_PCI_constr_1, CHOICE_constraint },
	asn_MBR_ServingCell_PCI_1,
	2,	/* Elements count */
	&asn_SPC_ServingCell_PCI_specs_1	/* Additional specs */
};

