(function_definition
  name: (identifier) @name) @item

(native_function_declaration
  name: (identifier) @name) @item

(structure_definition
  name: (identifier) @name) @item

(enum_definition
  name: (identifier) @name) @item

(protocol_definition
  name: (identifier) @name) @item

(structure_field
  name: (identifier) @name
  accessors: (property_accessor_block)) @item

(protocol_property_requirement
  name: (identifier) @name) @item

(extension_definition
  target: (named_type) @name) @item

(constructor_definition "init" @name) @item

(drop_definition "drop" @name) @item
