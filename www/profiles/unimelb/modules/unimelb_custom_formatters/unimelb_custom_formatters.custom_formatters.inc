<?php
/**
 * @file
 * unimelb_custom_formatters.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function unimelb_custom_formatters_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'email_address';
  $formatter->label = 'Email address';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = 'foreach($variables[\'#items\'] as $key => $val) { print \'<a href="mailto:\' . $val[\'value\'] . \'">\' . $val[\'value\'] . \'</a>\'; }';
  $formatter->fapi = '';
  $export['email_address'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'url_link';
  $formatter->label = 'URL link';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = 'foreach($variables[\'#items\'] as $key => $val) { print \'<div><a href="\' . $val[\'value\'] . \'">\' . $val[\'value\'] . \'</a></div>\'; }';
  $formatter->fapi = '';
  $export['url_link'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w120';
  $formatter->label = 'w120';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w120\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w120'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w220';
  $formatter->label = 'w220';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w220\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w220'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w360';
  $formatter->label = 'w360';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w360\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w360'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w480';
  $formatter->label = 'w480';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w480\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w480'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w680';
  $formatter->label = 'w680';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w680\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w680'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w700';
  $formatter->label = 'w700';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w700\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w700'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'w80';
  $formatter->label = 'w80';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$image = \'\'; foreach (element_children($variables[\'#items\']) as $delta) { $item = $variables[\'#items\'][$delta]; $image .= theme(\'image_style\', array(\'style_name\' => \'w80\', \'path\' => $item[\'uri\'])); } return t($image, array(\'html\' => TRUE));';
  $formatter->fapi = '';
  $export['w80'] = $formatter;

  return $export;
}
