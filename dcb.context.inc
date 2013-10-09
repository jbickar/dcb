<?php
/**
 * @file
 * dcb.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dcb_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'devel_block';
  $context->description = 'Place the devel blocks in the first sidebar';
  $context->tag = 'Devel';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-devel' => array(
          'module' => 'menu',
          'delta' => 'devel',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'devel-execute_php' => array(
          'module' => 'devel',
          'delta' => 'execute_php',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Devel');
  t('Place the devel blocks in the first sidebar');
  $export['devel_block'] = $context;

  return $export;
}
