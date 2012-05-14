<?php
/**
 * @file
 * unimelb_admin_shortcuts.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function unimelb_admin_shortcuts_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management:admin/content
  $menu_links['management:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Find and manage content.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-49',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/content3
  $menu_links['management:admin/content3'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content3',
    'router_path' => 'admin/content3',
    'link_title' => 'Manage content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
    'parent_path' => 'admin/content',
  );
  // Exported menu link: management:admin/pagestack
  $menu_links['management:admin/pagestack'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pagestack',
    'router_path' => 'admin/pagestack',
    'link_title' => 'Stacking order',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-48',
    'parent_path' => 'admin/content',
  );
  // Exported menu link: management:admin/people
  $menu_links['management:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage user accounts, roles, and permissions.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/people3
  $menu_links['management:admin/people3'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people3',
    'router_path' => 'admin/people3',
    'link_title' => 'Manage people',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
    'parent_path' => 'admin/people',
  );
  // Exported menu link: management:admin/shortcuts/unimelb_settings
  $menu_links['management:admin/shortcuts/unimelb_settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/shortcuts/unimelb_settings',
    'router_path' => 'admin/shortcuts/unimelb_settings',
    'link_title' => 'Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/structure/block
  $menu_links['management:admin/structure/block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure what block content appears in your site\'s sidebars and other regions.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/menu/manage/main-menu
  $menu_links['management:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Main menu',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/structure/menu',
  );
  // Exported menu link: management:imce
  $menu_links['management:imce'] = array(
    'menu_name' => 'management',
    'link_path' => 'imce',
    'router_path' => 'imce',
    'link_title' => 'Images and documents',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-49',
    'parent_path' => 'admin/content',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Content');
  t('Images and documents');
  t('Main menu');
  t('Manage content');
  t('Manage people');
  t('People');
  t('Settings');
  t('Stacking order');


  return $menu_links;
}
